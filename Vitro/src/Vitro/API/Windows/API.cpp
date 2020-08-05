#include "_pch.h"
#include "API.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/Input.h"
#include "Vitro/Events/KeyEvent.h"
#include "Vitro/Events/MouseEvent.h"
#include "Vitro/Events/WindowEvent.h"

#include <Windowsx.h>
#include <imgui/imgui_impl_win32.h>

// Forward declaration for IMGUI
IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

namespace Vitro::Windows
{
	std::function<void(Window&, Event&)> API::Dispatcher;
	KeyCode API::LastKeyCode;
	int API::KeyRepeats;

	void API::Initialize(std::function<void(Window&, Event&)> dispatcher)
	{
		static bool initialized;
		AssertCritical(!initialized, "Windows API already initialized.");

		Dispatcher = dispatcher;

		WNDCLASSW wc{0};
		wc.style			= CS_DBLCLKS;
		wc.lpfnWndProc		= NotifyEngine;
		wc.lpszClassName	= WindowClassName;
		wc.cbWndExtra		= sizeof(void*);
		RegisterClassW(&wc);

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
			case WM_DESTROY:	   OnWindowClose(w);					return 0;
			case WM_MOVE:		   OnWindowMove(w, lp);					return 0;
			case WM_SIZE:		   OnWindowSize(w, lp);					return 0;
			case WM_SETFOCUS:	   OnWindowFocus(w);					return 0;
			case WM_KILLFOCUS:	   OnWindowUnfocus(w);					return 0;
			case WM_SHOWWINDOW:	   if(wp) OnWindowOpen(w);				return 0;
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

	void API::OnWindowClose(Window& window)
	{
		Dispatcher(window, WindowCloseEvent(window));
	}

	void API::OnWindowMove(Window& window, LPARAM lp)
	{
		WindowMoveEvent e(window, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		Dispatcher(window, e);
	}

	void API::OnWindowSize(Window& window, LPARAM lp)
	{
		WindowSizeEvent e(window, LOWORD(lp), HIWORD(lp));
		Dispatcher(window, e);
	}

	void API::OnWindowFocus(Window& window)
	{
		Dispatcher(window, WindowFocusEvent(window));
	}

	void API::OnWindowUnfocus(Window& window)
	{
		Dispatcher(window, WindowUnfocusEvent(window));
	}

	void API::OnWindowOpen(Window& window)
	{
		Dispatcher(window, WindowOpenEvent(window));
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
		Dispatcher(window, KeyDownEvent(key, KeyRepeats));
	}

	void API::OnKeyUp(Window& window, WPARAM wp)
	{
		LastKeyCode = KeyCode::None;
		KeyRepeats = 0;
		KeyCode key = static_cast<KeyCode>(wp);
		Input::KeyStates[key] = false;
		Dispatcher(window, KeyUpEvent(key));
	}

	void API::OnTextType(Window& window, WPARAM wp)
	{
		auto character = NarrowChars({static_cast<wchar_t>(wp)});
		character.resize(character.find('\0'));
		Dispatcher(window, TextTypeEvent(LastKeyCode, character));
	}

	void API::OnMouseMove(Window& window, LPARAM lp)
	{
		auto pos = Input::MousePosition = Int2(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		Dispatcher(window, MouseMoveEvent(pos.X, pos.Y));
	}

	void API::OnMouseDown(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = true;
		Dispatcher(window, MouseDownEvent(button));
	}

	void API::OnMouseUp(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = false;
		Dispatcher(window, MouseUpEvent(button));
	}

	void API::OnDoubleClick(Window& window, MouseCode button)
	{
		Dispatcher(window, DoubleClickEvent(button));
	}

	void API::OnMouseScrollVertical(Window& window, WPARAM wp)
	{
		float yOffset = static_cast<short>(HIWORD(wp)) / static_cast<float>(WHEEL_DELTA);
		Dispatcher(window, MouseScrollEvent(0, yOffset));
	}

	void API::OnMouseScrollHorizontal(Window& window, WPARAM wp)
	{
		// X axis is inverted for consistency with Linux and macOS.
		float xOffset = static_cast<short>(HIWORD(wp)) / -static_cast<float>(WHEEL_DELTA);
		Dispatcher(window, MouseScrollEvent(xOffset, 0));
	}

	MouseCode API::GetMouseExtra(WPARAM wp)
	{
		return static_cast<MouseCode>(HIWORD(wp) + 3);
	}
}
