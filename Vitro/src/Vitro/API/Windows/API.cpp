#include "_pch.h"
#include "API.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Diagnostics/Log.h"
#include "Vitro/Events/Key/KeyCode.h"
#include "Vitro/Events/Key/KeyDownEvent.h"
#include "Vitro/Events/Key/KeyUpEvent.h"
#include "Vitro/Events/Key/TextTypeEvent.h"
#include "Vitro/Events/Mouse/DoubleClickEvent.h"
#include "Vitro/Events/Mouse/MouseCode.h"
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

namespace Vitro::Windows
{
	bool API::IsInitialized;
	HINSTANCE API::InstanceHandle;
	PIXELFORMATDESCRIPTOR API::PixelFormatDescriptor;

	void API::Initialize()
	{
		if(IsInitialized)
		{
			auto error = "Windows API already initialized.";
			LogEngineFatal(error);
			throw std::runtime_error(error);
		}

		InstanceHandle = GetModuleHandleW(nullptr);

		WNDCLASSW wc{};
		wc.style = CS_OWNDC | CS_DBLCLKS;
		wc.lpfnWndProc = NotifyEngine;
		wc.hInstance = InstanceHandle;
		wc.lpszClassName = WindowClassName;
		RegisterClassW(&wc);

	#if $OPENGL
		PixelFormatDescriptor =
		{
			sizeof(PIXELFORMATDESCRIPTOR), 1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0,	0, 0, 0, 0, 0, 0, 24, 8, 0,
			PFD_MAIN_PLANE, 0, 0, 0, 0
		};
	#endif

		IsInitialized = true;
	}

	LRESULT API::NotifyEngine(HWND window, UINT message, WPARAM wp, LPARAM lp)
	{
		static KeyCode lastKeyCode;
		static int repeats = 0;
		uint64_t wID = (uint64_t)window; // TODO: convert this to static_cast?
		Event* e;
		switch(message)
		{
			case WM_DESTROY: e = &WindowCloseEvent(wID); break;
			case WM_SIZE: e = &WindowSizeEvent(wID, LOWORD(lp), HIWORD(lp)); break;
			case WM_SETFOCUS: e = &WindowFocusEvent(wID); break;
			case WM_KILLFOCUS: e = &WindowUnfocusEvent(wID); break;
			case WM_MOVE: e = &WindowMoveEvent(wID, GET_X_LPARAM(lp), GET_Y_LPARAM(lp)); break;
			case WM_MOUSEMOVE: e = &MouseMoveEvent(GET_X_LPARAM(lp), GET_Y_LPARAM(lp)); break;
			case WM_LBUTTONDOWN: e = &MouseDownEvent(MouseCode::Primary); break;
			case WM_RBUTTONDOWN: e = &MouseDownEvent(MouseCode::Secondary); break;
			case WM_MBUTTONDOWN: e = &MouseDownEvent(MouseCode::Wheel); break;
			case WM_LBUTTONUP: e = &MouseUpEvent(MouseCode::Primary); break;
			case WM_RBUTTONUP: e = &MouseUpEvent(MouseCode::Secondary); break;
			case WM_MBUTTONUP: e = &MouseUpEvent(MouseCode::Wheel); break;
			case WM_LBUTTONDBLCLK: e = &DoubleClickEvent(MouseCode::Primary); break;
			case WM_RBUTTONDBLCLK: e = &DoubleClickEvent(MouseCode::Secondary); break;
			case WM_MBUTTONDBLCLK: e = &DoubleClickEvent(MouseCode::Wheel); break;
			case WM_MOUSEWHEEL:
			{
				float yOffset = static_cast<short>(HIWORD(wp)) / static_cast<float>(WHEEL_DELTA);
				e = &MouseScrollEvent(0, yOffset); break;
			}
			case WM_MOUSEHWHEEL:
			{
				// X axis is inverted for consistency with Linux and macOS.
				float xOffset = static_cast<short>(HIWORD(wp)) / -static_cast<float>(WHEEL_DELTA);
				e = &MouseScrollEvent(xOffset, 0); break;
			}
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:
			{
				if(lastKeyCode == static_cast<KeyCode>(wp))
					repeats++;
				else
					repeats = 0;
				lastKeyCode = static_cast<KeyCode>(wp);
				e = &KeyDownEvent(lastKeyCode, repeats); break;
			}
			case WM_KEYUP:
			case WM_SYSKEYUP:
			{
				lastKeyCode = KeyCode::None;
				repeats = 0;
				e = &KeyUpEvent(static_cast<KeyCode>(wp)); break;
			}
			case WM_CHAR:
			case WM_SYSCHAR:
			case WM_UNICHAR:
			{
				char* character = NarrowChars((wchar_t*)&wp);
				TextTypeEvent event(lastKeyCode, std::string(character));
				free(character);
				Engine::DispatchToWindow(wID, event);
				if(message == WM_UNICHAR)
					return wp == UNICODE_NOCHAR;
				return 0;
			}
			case WM_XBUTTONDOWN:
			{
				MouseDownEvent e(static_cast<MouseCode>(HIWORD(wp) + 3));
				Engine::DispatchToWindow(wID, e); return TRUE;
			}
			case WM_XBUTTONUP:
			{
				MouseUpEvent e(static_cast<MouseCode>(HIWORD(wp) + 3));
				Engine::DispatchToWindow(wID, e); return TRUE;
			}
			case WM_XBUTTONDBLCLK:
			{
				DoubleClickEvent e(static_cast<MouseCode>(HIWORD(wp) + 3));
				Engine::DispatchToWindow(wID, e); return TRUE;
			}
			default:
				return DefWindowProcW(window, message, wp, lp);
		}
		Engine::DispatchToWindow(wID, *e);
		return 0;
	}

	void API::SetConsoleColors(uint8_t colorMask)
	{
		static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, colorMask);
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
}
