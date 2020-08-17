#include "_pch.h"
#include "API.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/Input.h"
#include "Vitro/Events/KeyEvent.h"
#include "Vitro/Events/MouseEvent.h"
#include "Vitro/Events/WindowEvent.h"
#include "Vitro/Utility/StackArray.h"

#include <windowsx.h>
#include <imgui/imgui_impl_win32.h>



#include <Vitro\Utility\Log.h> //TODO

// Forward declaration for IMGUI
IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

namespace Vitro::Windows
{
	void API::Initialize()
	{
		static bool initialized;
		AssertCritical(!initialized, "Windows API already initialized.");

		WNDCLASSW wc {0};
		wc.style			= CS_DBLCLKS;
		wc.lpfnWndProc		= NotifyEngine;
		wc.lpszClassName	= WindowClassName;
		wc.cbWndExtra		= sizeof(void*);
		auto wcResult = RegisterClassW(&wc);
		AssertCritical(SUCCEEDED(wcResult), "Could not create Windows API window class.");

		RAWINPUTDEVICE rid {0};
		rid.usUsagePage	= 0x01; // Usage page constant for generic desktop controls
		rid.usUsage		= 0x02; // Usage constant for a generic mouse
		auto ridResult = RegisterRawInputDevices(&rid, 1, sizeof(rid));
		AssertCritical(ridResult, "Could not get raw mouse input device.");

		initialized = true;
	}

	void API::SetConsoleColors(uint8_t colorMask)
	{
		static auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(outHandle, colorMask);
	}

	std::wstring API::WidenChars(const std::string& s)
	{
		int length = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, nullptr, 0);
		std::wstring ws(length, 0);
		MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, &ws[0], length);
		return ws;
	}

	std::string API::NarrowChars(const std::wstring& ws)
	{
		int length = WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), -1, nullptr, 0, nullptr, nullptr);
		std::string s(length, 0);
		WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), -1, &s[0], length, nullptr, nullptr);
		return s;
	}

	LRESULT API::NotifyEngine(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		ImGui_ImplWin32_WndProcHandler(wnd, msg, wp, lp);
		auto& w = *reinterpret_cast<Window*>(GetWindowLongPtr(wnd, 0));
		switch(msg)
		{
			case WM_MOVE:		   OnWindowMove(w, lp);					return 0;
			case WM_SIZE:		   OnWindowSize(w, lp);					return 0;
			case WM_SETFOCUS:	   OnWindowFocus(w);					return 0;
			case WM_KILLFOCUS:	   OnWindowUnfocus(w);					return 0;
			case WM_CLOSE:		   OnWindowClose(w);					return 0;
			case WM_SHOWWINDOW:	   if(wp) OnWindowOpen(w);				return 0;
			case WM_INPUT:		   OnRawInput(w, lp);					return 0;
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:	   OnKeyDown(w, wp);					return 0;
			case WM_KEYUP:
			case WM_SYSKEYUP:	   OnKeyUp(w, wp);						return 0;
			case WM_CHAR:
			case WM_SYSCHAR:	   OnTextType(w, wp);					return 0;
			case WM_UNICHAR:	   OnTextType(w, wp);					return wp == UNICODE_NOCHAR;
			case WM_MOUSEMOVE:	   OnMouseMove(w, lp);					return 0;
			case WM_LBUTTONDOWN:   OnMouseDown(w, MouseCode::Mouse1);	return 0;
			case WM_RBUTTONDOWN:   OnMouseDown(w, MouseCode::Mouse2);	return 0;
			case WM_MBUTTONDOWN:   OnMouseDown(w, MouseCode::Wheel);	return 0;
			case WM_XBUTTONDOWN:   OnMouseDown(w, GetMouseExtra(wp));	return true;
			case WM_LBUTTONUP:	   OnMouseUp(w, MouseCode::Mouse1);		return 0;
			case WM_RBUTTONUP:	   OnMouseUp(w, MouseCode::Mouse2);		return 0;
			case WM_MBUTTONUP:	   OnMouseUp(w, MouseCode::Wheel);		return 0;
			case WM_XBUTTONUP:	   OnMouseUp(w, GetMouseExtra(wp));		return true;
			case WM_LBUTTONDBLCLK: OnDoubleClick(w, MouseCode::Mouse1);	return 0;
			case WM_RBUTTONDBLCLK: OnDoubleClick(w, MouseCode::Mouse2);	return 0;
			case WM_MBUTTONDBLCLK: OnDoubleClick(w, MouseCode::Wheel);	return 0;
			case WM_XBUTTONDBLCLK: OnDoubleClick(w, GetMouseExtra(wp));	return true;
			case WM_MOUSEWHEEL:	   OnMouseScrollVertical(w, wp);		return 0;
			case WM_MOUSEHWHEEL:   OnMouseScrollHorizontal(w, wp);		return 0;
			default:			   return DefWindowProcW(wnd, msg, wp, lp);
		}
	}

	void API::OnWindowMove(Window& window, LPARAM lp)
	{
		WindowMoveEvent e(window, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		window.OnEvent(e);
	}

	void API::OnWindowSize(Window& window, LPARAM lp)
	{
		WindowSizeEvent e(window, LOWORD(lp), HIWORD(lp));
		window.OnEvent(e);
	}

	void API::OnWindowFocus(Window& window)
	{
		window.OnEvent(WindowFocusEvent(window));
	}

	void API::OnWindowUnfocus(Window& window)
	{
		window.OnEvent(WindowUnfocusEvent(window));
	}

	void API::OnWindowClose(Window& window)
	{
		WindowCloseEvent e(window);
		window.OnEvent(e);
		Engine::Get().OnWindowClose(e);
		window.Close();
	}

	void API::OnWindowOpen(Window& window)
	{
		WindowOpenEvent e(window);
		window.OnEvent(e);
		Engine::Get().OnWindowOpen(e);
	}

	void API::OnRawInput(Window& window, LPARAM lp)
	{
		UINT size = 0;
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lp), RID_INPUT, nullptr, &size,
						sizeof(RAWINPUTHEADER));
		StackArray<BYTE> bytes(size);
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lp), RID_INPUT, bytes.Raw(), &size,
						sizeof(RAWINPUTHEADER));
		auto& input = *reinterpret_cast<RAWINPUT*>(bytes.Raw());
		window.OnEvent(MouseMoveEvent(input.data.mouse.lLastX, -input.data.mouse.lLastY));
	}

	void API::OnKeyDown(Window& window, WPARAM wp)
	{
		auto key = static_cast<KeyCode>(wp);
		if(LastKeyCode == key)
			KeyRepeats++;
		else
			KeyRepeats = 0;
		LastKeyCode = key;
		Input::KeyStates[key] = true;
		window.OnEvent(KeyDownEvent(key, KeyRepeats));
	}

	void API::OnKeyUp(Window& window, WPARAM wp)
	{
		LastKeyCode = KeyCode::None;
		KeyRepeats = 0;
		KeyCode key = static_cast<KeyCode>(wp);
		Input::KeyStates[key] = false;
		window.OnEvent(KeyUpEvent(key));
	}

	void API::OnTextType(Window& window, WPARAM wp)
	{
		auto character = NarrowChars({static_cast<wchar_t>(wp)});
		character.resize(character.find('\0'));
		window.OnEvent(TextTypeEvent(LastKeyCode, character));
	}

	void API::OnMouseMove(Window& window, LPARAM lp)
	{
		Input::MousePosition = Int2(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
	}

	void API::OnMouseDown(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = true;
		window.OnEvent(MouseDownEvent(button));
	}

	void API::OnMouseUp(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = false;
		window.OnEvent(MouseUpEvent(button));
	}

	void API::OnDoubleClick(Window& window, MouseCode button)
	{
		window.OnEvent(DoubleClickEvent(button));
	}

	void API::OnMouseScrollVertical(Window& window, WPARAM wp)
	{
		float yOffset = static_cast<short>(HIWORD(wp)) / static_cast<float>(WHEEL_DELTA);
		window.OnEvent(MouseScrollEvent(0, yOffset));
	}

	void API::OnMouseScrollHorizontal(Window& window, WPARAM wp)
	{
		// X axis is inverted for consistency with Linux and macOS.
		float xOffset = static_cast<short>(HIWORD(wp)) / -static_cast<float>(WHEEL_DELTA);
		window.OnEvent(MouseScrollEvent(xOffset, 0));
	}

	MouseCode API::GetMouseExtra(WPARAM wp)
	{
		return static_cast<MouseCode>(HIWORD(wp) + 3);
	}
}
