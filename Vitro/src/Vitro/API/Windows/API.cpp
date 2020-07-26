#include "_pch.h"
#include "API.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Diagnostics/Log.h"
#include "Vitro/Events/Input.h"
#include "Vitro/Events/Key/KeyDownEvent.h"
#include "Vitro/Events/Key/KeyUpEvent.h"
#include "Vitro/Events/Key/TextTypeEvent.h"
#include "Vitro/Events/Mouse/DoubleClickEvent.h"
#include "Vitro/Events/Mouse/MouseDownEvent.h"
#include "Vitro/Events/Mouse/MouseMoveEvent.h"
#include "Vitro/Events/Mouse/MouseScrollEvent.h"
#include "Vitro/Events/Mouse/MouseUpEvent.h"
#include "Vitro/Events/Window/WindowCloseEvent.h"
#include "Vitro/Events/Window/WindowFocusEvent.h"
#include "Vitro/Events/Window/WindowMoveEvent.h"
#include "Vitro/Events/Window/WindowSizeEvent.h"
#include "Vitro/Events/Window/WindowUnfocusEvent.h"

#include <iostream>
#include <Windowsx.h>
#include <imgui/imgui_impl_win32.h>

// Forward declaration for IMGUI
IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

namespace Vitro::Windows
{
	HANDLE API::StdOutHandle;
	HINSTANCE API::InstanceHandle;
	KeyCode API::LastKeyCode;
	int API::KeyRepeats;

	void API::Initialize()
	{
		static bool Initialized;
		Assert(!Initialized, "Windows API already initialized.");

		StdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		WNDCLASSW wc{};
		wc.style = CS_DBLCLKS;
		wc.lpfnWndProc = NotifyEngine;
		wc.hInstance = InstanceHandle = GetModuleHandleW(nullptr);
		wc.lpszClassName = WindowClassName;
		wc.cbWndExtra = sizeof(void*);
		RegisterClassW(&wc);

		Initialized = true;
	}

	LRESULT API::NotifyEngine(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		ImGui_ImplWin32_WndProcHandler(wnd, msg, wp, lp);
		Window& w = *reinterpret_cast<Window*>(GetWindowLongPtr(wnd, 0));
		switch(msg)
		{
			case WM_DESTROY:	   OnWindowClose(w);					return 0;
			case WM_MOVE:		   OnWindowMove(w, lp);					return 0;
			case WM_SIZE:		   OnWindowSize(w, lp);					return 0;
			case WM_SETFOCUS:	   OnWindowFocus(w);					return 0;
			case WM_KILLFOCUS:	   OnWindowUnfocus(w);					return 0;
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
			case WM_XBUTTONDOWN:   OnMouseDown(w, GetMouseExtra(wp));	return TRUE;
			case WM_LBUTTONUP:	   OnMouseUp(w, MouseCode::Mouse1);		return 0;
			case WM_RBUTTONUP:	   OnMouseUp(w, MouseCode::Mouse2);		return 0;
			case WM_MBUTTONUP:	   OnMouseUp(w, MouseCode::Wheel);		return 0;
			case WM_XBUTTONUP:	   OnMouseUp(w, GetMouseExtra(wp));		return TRUE;
			case WM_LBUTTONDBLCLK: OnDoubleClick(w, MouseCode::Mouse1);	return 0;
			case WM_RBUTTONDBLCLK: OnDoubleClick(w, MouseCode::Mouse2);	return 0;
			case WM_MBUTTONDBLCLK: OnDoubleClick(w, MouseCode::Wheel);	return 0;
			case WM_XBUTTONDBLCLK: OnDoubleClick(w, GetMouseExtra(wp));	return TRUE;
			case WM_MOUSEWHEEL:	   OnMouseScrollVertical(w, wp);		return 0;
			case WM_MOUSEHWHEEL:   OnMouseScrollHorizontal(w, wp);		return 0;
			default:			   return DefWindowProcW(wnd, msg, wp, lp);
		}
	}

	wchar_t* API::WidenChars(const char* str)
	{
		int length = MultiByteToWideChar(CP_UTF8, 0, str, -1, nullptr, 0);
		wchar_t* wstr = static_cast<wchar_t*>(calloc(length, sizeof(wchar_t)));
		MultiByteToWideChar(CP_UTF8, 0, str, -1, wstr, length);
		return wstr;
	}

	char* API::NarrowChars(const wchar_t* wstr)
	{
		int length = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
		char* str = static_cast<char*>(calloc(length, sizeof(char)));
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, length, nullptr, nullptr);
		return str;
	}

	void API::SetConsoleColors(uint8_t colorMask)
	{
		SetConsoleTextAttribute(StdOutHandle, colorMask);
	}

	MouseCode API::GetMouseExtra(WPARAM wp)
	{
		return static_cast<MouseCode>(HIWORD(wp) + 3);
	}

	void API::OnKeyDown(Window& window, WPARAM wp)
	{
		if(LastKeyCode == static_cast<KeyCode>(wp))
			KeyRepeats++;
		else
			KeyRepeats = 0;
		LastKeyCode = static_cast<KeyCode>(wp);
		Input::KeyStates[LastKeyCode] = true;
		Engine::DispatchToWindow(window, KeyDownEvent(LastKeyCode, KeyRepeats));
	}

	void API::OnKeyUp(Window& window, WPARAM wp)
	{
		LastKeyCode = KeyCode::None;
		KeyRepeats = 0;
		KeyCode key = static_cast<KeyCode>(wp);
		Input::KeyStates[key] = false;
		Engine::DispatchToWindow(window, KeyUpEvent(key));
	}

	void API::OnTextType(Window& window, WPARAM wp)
	{
		char* character = NarrowChars((wchar_t*)&wp);
		TextTypeEvent e(LastKeyCode, std::string(character));
		free(character);
		Engine::DispatchToWindow(window, e);
	}

	void API::OnDoubleClick(Window& window, MouseCode button)
	{
		Engine::DispatchToWindow(window, DoubleClickEvent(button));
	}

	void API::OnMouseDown(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = true;
		Engine::DispatchToWindow(window, MouseDownEvent(button));
	}

	void API::OnMouseMove(Window& window, LPARAM lp)
	{
		auto pos = Input::MousePosition = Int2(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		Engine::DispatchToWindow(window, MouseMoveEvent(pos.X, pos.Y));
	}

	void API::OnMouseScrollHorizontal(Window& window, WPARAM wp)
	{
		// X axis is inverted for consistency with Linux and macOS.
		float xOffset = static_cast<short>(HIWORD(wp)) / -static_cast<float>(WHEEL_DELTA);
		Engine::DispatchToWindow(window, MouseScrollEvent(xOffset, 0));
	}

	void API::OnMouseScrollVertical(Window& window, WPARAM wp)
	{
		float yOffset = static_cast<short>(HIWORD(wp)) / static_cast<float>(WHEEL_DELTA);
		Engine::DispatchToWindow(window, MouseScrollEvent(0, yOffset));
	}

	void API::OnMouseUp(Window& window, MouseCode button)
	{
		Input::MouseStates[button] = false;
		Engine::DispatchToWindow(window, MouseUpEvent(button));
	}

	void API::OnWindowClose(Window& window)
	{
		Engine::DispatchToWindow(window, WindowCloseEvent(window));
	}

	void API::OnWindowFocus(Window& window)
	{
		Engine::DispatchToWindow(window, WindowFocusEvent(window));
	}

	void API::OnWindowMove(Window& window, LPARAM lp)
	{
		WindowMoveEvent e(window, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		Engine::DispatchToWindow(window, e);
	}

	void API::OnWindowSize(Window& window, LPARAM lp)
	{
		WindowSizeEvent e(window, LOWORD(lp), HIWORD(lp));
		Engine::DispatchToWindow(window, e);
	}

	void API::OnWindowUnfocus(Window& window)
	{
		Engine::DispatchToWindow(window, WindowUnfocusEvent(window));
	}
}
