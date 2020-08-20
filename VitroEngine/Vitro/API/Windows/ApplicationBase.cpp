#include "_pch.h"
#include "ApplicationBase.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/Input.h"
#include "Vitro/Events/KeyEvent.h"
#include "Vitro/Events/MouseEvent.h"
#include "Vitro/Events/WindowEvent.h"
#include "Vitro/Utility/StackArray.h"

#include <windowsx.h>
#include <imgui/imgui_impl_win32.h>

// Forward declaration for imgui
IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

namespace Vitro::Windows
{
	ApplicationBase::ApplicationBase()
	{
		static bool initialized;
		AssertCritical(!initialized, "Windows API already initialized.");

		WNDCLASSW wc {0};
		wc.style			= CS_DBLCLKS;
		wc.lpfnWndProc		= ReceiveMessages;
		wc.lpszClassName	= WindowClassName;
		wc.cbWndExtra		= sizeof(void*);
		auto wcRes = RegisterClassW(&wc);
		AssertCritical(SUCCEEDED(wcRes), "Could not create Windows API window class.");

		RAWINPUTDEVICE rid {0};
		rid.usUsagePage	= 0x01; // Usage page constant for generic desktop controls
		rid.usUsage		= 0x02; // Usage constant for a generic mouse
		auto ridRes = RegisterRawInputDevices(&rid, 1, sizeof(rid));
		AssertCritical(ridRes, "Could not get raw mouse input device.");

		initialized = true;
	}

	std::wstring ApplicationBase::WidenChars(const std::string& s)
	{
		int length = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, nullptr, 0);
		std::wstring ws(length, 0);
		MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, &ws[0], length);
		return ws;
	}

	std::string ApplicationBase::NarrowChars(const std::wstring& ws)
	{
		int length = WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), -1, nullptr, 0, nullptr, nullptr);
		std::string s(length, 0);
		WideCharToMultiByte(CP_UTF8, 0, ws.c_str(), -1, &s[0], length, nullptr, nullptr);
		return s;
	}

	void ApplicationBase::SetConsoleColors(uint8_t colorMask)
	{
		static auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(outHandle, colorMask);
	}

	void ApplicationBase::PollEvents()
	{
		MSG msg;
		while(PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	LRESULT ApplicationBase::ReceiveMessages(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		return Engine::Get().ForwardMessages(wnd, msg, wp, lp);
	}

	LRESULT ApplicationBase::ForwardMessages(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
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
			case WM_SYSCHAR:	   OnKeyText(w, wp);					return 0;
			case WM_UNICHAR:	   OnKeyText(w, wp);					return wp == UNICODE_NOCHAR;
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

	void ApplicationBase::OnWindowMove(Window& window, LPARAM lp)
	{
		WindowMoveEvent e(window, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		window.OnEvent(e);
	}

	void ApplicationBase::OnWindowSize(Window& window, LPARAM lp)
	{
		WindowSizeEvent e(window, LOWORD(lp), HIWORD(lp));
		window.OnEvent(e);
	}

	void ApplicationBase::OnWindowFocus(Window& window)
	{
		WindowFocusEvent e(window);
		window.OnEvent(e);
	}

	void ApplicationBase::OnWindowUnfocus(Window& window)
	{
		WindowUnfocusEvent e(window);
		window.OnEvent(e);
	}

	void ApplicationBase::OnWindowClose(Window& window)
	{
		WindowCloseEvent e(window);
		window.OnEvent(e);
		EraseWindow(window);
		window.Close();
	}

	void ApplicationBase::OnWindowOpen(Window& window)
	{
		WindowOpenEvent e(window);
		window.OnEvent(e);
		EmplaceWindow(window);
	}

	void ApplicationBase::OnRawInput(Window& window, LPARAM lp)
	{
		UINT size = 0;
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lp), RID_INPUT, nullptr, &size,
						sizeof(RAWINPUTHEADER));
		StackArray<BYTE> bytes(size);
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lp), RID_INPUT, bytes.Raw(), &size,
						sizeof(RAWINPUTHEADER));
		auto& input = *reinterpret_cast<RAWINPUT*>(bytes.Raw());
		MouseMoveEvent e(input.data.mouse.lLastX, -input.data.mouse.lLastY);
		window.OnEvent(e);
	}

	void ApplicationBase::OnKeyDown(Window& window, WPARAM wp)
	{
		auto key = static_cast<KeyCode>(wp);
		if(LastKeyCode == key)
			KeyRepeats++;
		else
			KeyRepeats = 0;
		LastKeyCode = key;
		Input::KeyStates[key] = true;
		KeyDownEvent e(key, KeyRepeats);
		window.OnEvent(e);
	}

	void ApplicationBase::OnKeyUp(Window& window, WPARAM wp)
	{
		LastKeyCode = KeyCode::None;
		KeyRepeats = 0;
		KeyCode key = static_cast<KeyCode>(wp);
		Input::KeyStates[key] = false;
		KeyUpEvent e(key);
		window.OnEvent(e);
	}

	void ApplicationBase::OnKeyText(Window& window, WPARAM wp)
	{
		auto character = NarrowChars({static_cast<wchar_t>(wp)});
		character.resize(character.find('\0'));
		KeyTextEvent e(LastKeyCode, character);
		window.OnEvent(e);
	}

	void ApplicationBase::OnMouseMove(Window& window, LPARAM lp)
	{
		Input::MousePosition = Int2(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
	}

	void ApplicationBase::OnMouseDown(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = true;
		MouseDownEvent e(button);
		window.OnEvent(e);
	}

	void ApplicationBase::OnMouseUp(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = false;
		MouseUpEvent e(button);
		window.OnEvent(e);
	}

	void ApplicationBase::OnDoubleClick(Window& window, MouseCode button)
	{
		DoubleClickEvent e(button);
		window.OnEvent(e);
	}

	void ApplicationBase::OnMouseScrollVertical(Window& window, WPARAM wp)
	{
		float yOffset = static_cast<short>(HIWORD(wp)) / static_cast<float>(WHEEL_DELTA);
		MouseScrollEvent e(0, yOffset);
		window.OnEvent(e);
	}

	void ApplicationBase::OnMouseScrollHorizontal(Window& window, WPARAM wp)
	{
		// X axis is inverted for consistency with Linux and macOS.
		float xOffset = static_cast<short>(HIWORD(wp)) / -static_cast<float>(WHEEL_DELTA);
		MouseScrollEvent e(xOffset, 0);
		window.OnEvent(e);
	}

	MouseCode ApplicationBase::GetMouseExtra(WPARAM wp)
	{
		return static_cast<MouseCode>(HIWORD(wp) + 3);
	}
}
