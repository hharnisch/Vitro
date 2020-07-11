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

#include <Windowsx.h>
#include <imgui/imgui_impl_win32.h>

// Forward declaration for IMGUI
IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

namespace Vitro::Windows
{
	HINSTANCE API::InstanceHandle;
	PIXELFORMATDESCRIPTOR API::PixelFormatDescriptor;
	bool API::IsInitialized;
	uint64_t API::MessageWindowID;
	KeyCode API::LastKeyCode;
	int API::KeyRepeats;

	void API::Initialize()
	{
		if(IsInitialized)
		{
			auto error = "Windows API already initialized.";
			LogEngineFatal(error);
			throw std::runtime_error(error);
		}

		WNDCLASSW wc{};
		wc.style = CS_OWNDC | CS_DBLCLKS;
		wc.lpfnWndProc = NotifyEngine;
		wc.hInstance = InstanceHandle = GetModuleHandleW(nullptr);
		wc.lpszClassName = WindowClassName;
		RegisterClassW(&wc);

	#if $OPENGL
		PixelFormatDescriptor =
		{
			sizeof(PIXELFORMATDESCRIPTOR), 1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA,
			32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
		};
	#endif

		IsInitialized = true;
	}

	LRESULT API::NotifyEngine(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		ImGui_ImplWin32_WndProcHandler(wnd, msg, wp, lp);
		MessageWindowID = (uint64_t)wnd; // convert this to static_cast?
		switch(msg)
		{
			case WM_DESTROY:	   OnWindowClose();						return 0;
			case WM_MOVE:		   OnWindowMove(lp);					return 0;
			case WM_SIZE:		   OnWindowSize(lp);					return 0;
			case WM_SETFOCUS:	   OnWindowFocus();						return 0;
			case WM_KILLFOCUS:	   OnWindowUnfocus();					return 0;
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:	   OnKeyDown(wp);						return 0;
			case WM_KEYUP:
			case WM_SYSKEYUP:	   OnKeyUp(wp);							return 0;
			case WM_CHAR:
			case WM_SYSCHAR:	   OnTextType(wp);						return 0;
			case WM_UNICHAR:	   OnTextType(wp);						return wp == UNICODE_NOCHAR;
			case WM_MOUSEMOVE:	   OnMouseMove(lp);						return 0;
			case WM_LBUTTONDOWN:   OnMouseDown(MouseCode::Primary);		return 0;
			case WM_RBUTTONDOWN:   OnMouseDown(MouseCode::Secondary);	return 0;
			case WM_MBUTTONDOWN:   OnMouseDown(MouseCode::Wheel);		return 0;
			case WM_XBUTTONDOWN:   OnMouseDown(GetExtraButton(wp));		return TRUE;
			case WM_LBUTTONUP:	   OnMouseUp(MouseCode::Primary);		return 0;
			case WM_RBUTTONUP:	   OnMouseUp(MouseCode::Secondary);		return 0;
			case WM_MBUTTONUP:	   OnMouseUp(MouseCode::Wheel);			return 0;
			case WM_XBUTTONUP:	   OnMouseUp(GetExtraButton(wp));		return TRUE;
			case WM_LBUTTONDBLCLK: OnDoubleClick(MouseCode::Primary);	return 0;
			case WM_RBUTTONDBLCLK: OnDoubleClick(MouseCode::Secondary);	return 0;
			case WM_MBUTTONDBLCLK: OnDoubleClick(MouseCode::Wheel);		return 0;
			case WM_XBUTTONDBLCLK: OnDoubleClick(GetExtraButton(wp));	return TRUE;
			case WM_MOUSEWHEEL:	   OnMouseScrollVertical(wp);			return 0;
			case WM_MOUSEHWHEEL:   OnMouseScrollHorizontal(wp);			return 0;
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
		static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, colorMask);
	}

	MouseCode API::GetExtraButton(WPARAM wp)
	{
		return static_cast<MouseCode>(HIWORD(wp) + 3);
	}

	void API::OnKeyDown(WPARAM wp)
	{
		if(LastKeyCode == static_cast<KeyCode>(wp))
			KeyRepeats++;
		else
			KeyRepeats = 0;
		LastKeyCode = static_cast<KeyCode>(wp);
		Input::KeyStates[LastKeyCode] = true;
		Engine::DispatchToWindow(MessageWindowID, KeyDownEvent(LastKeyCode, KeyRepeats));
	}

	void API::OnKeyUp(WPARAM wp)
	{
		LastKeyCode = KeyCode::None;
		KeyRepeats = 0;
		KeyCode key = static_cast<KeyCode>(wp);
		Input::KeyStates[key] = false;
		Engine::DispatchToWindow(MessageWindowID, KeyUpEvent(key));
	}

	void API::OnTextType(WPARAM wp)
	{
		char* character = NarrowChars((wchar_t*)&wp);
		TextTypeEvent e(LastKeyCode, std::string(character));
		free(character);
		Engine::DispatchToWindow(MessageWindowID, e);
	}

	void API::OnDoubleClick(MouseCode button)
	{
		Engine::DispatchToWindow(MessageWindowID, DoubleClickEvent(button));
	}

	void API::OnMouseDown(MouseCode button)
	{
		Input::MouseStates[button] = true;
		Engine::DispatchToWindow(MessageWindowID, MouseDownEvent(button));
	}

	void API::OnMouseMove(LPARAM lp)
	{
		auto pos = Input::MousePosition = {GET_X_LPARAM(lp), GET_Y_LPARAM(lp)};
		Engine::DispatchToWindow(MessageWindowID, MouseMoveEvent(pos.X, pos.Y));
	}

	void API::OnMouseScrollHorizontal(WPARAM wp)
	{
		// X axis is inverted for consistency with Linux and macOS.
		float xOffset = static_cast<short>(HIWORD(wp)) / -static_cast<float>(WHEEL_DELTA);
		Engine::DispatchToWindow(MessageWindowID, MouseScrollEvent(xOffset, 0));
	}

	void API::OnMouseScrollVertical(WPARAM wp)
	{
		float yOffset = static_cast<short>(HIWORD(wp)) / static_cast<float>(WHEEL_DELTA);
		Engine::DispatchToWindow(MessageWindowID, MouseScrollEvent(0, yOffset));
	}

	void API::OnMouseUp(MouseCode button)
	{
		Input::MouseStates[button] = false;
		Engine::DispatchToWindow(MessageWindowID, MouseUpEvent(button));
	}

	void API::OnWindowClose()
	{
		Engine::DispatchToWindow(MessageWindowID, WindowCloseEvent(MessageWindowID));
	}

	void API::OnWindowFocus()
	{
		Engine::DispatchToWindow(MessageWindowID, WindowFocusEvent(MessageWindowID));
	}

	void API::OnWindowMove(LPARAM lp)
	{
		WindowMoveEvent e(MessageWindowID, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		Engine::DispatchToWindow(MessageWindowID, e);
	}

	void API::OnWindowSize(LPARAM lp)
	{
		WindowSizeEvent e(MessageWindowID, LOWORD(lp), HIWORD(lp));
		Engine::DispatchToWindow(MessageWindowID, e);
	}

	void API::OnWindowUnfocus()
	{
		Engine::DispatchToWindow(MessageWindowID, WindowUnfocusEvent(MessageWindowID));
	}
}
