#pragma once

#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/Key/KeyCode.h"
#include "Vitro/Events/Mouse/MouseCode.h"

#include <Windows.h>

namespace Vitro::Windows
{
	class API
	{
	public:
		static constexpr auto WindowClassName = L"VITRO";
		static HANDLE StdOutHandle;
		static HINSTANCE InstanceHandle;

		static void Initialize();

		// Exists only for the Windows API to deliver messages.
		static LRESULT CALLBACK NotifyEngine(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

		// Result must be deallocated manually!
		static wchar_t* WidenChars(const char* str);

		// Result must be deallocated manually!
		static char* NarrowChars(const wchar_t* wstr);

		static void SetConsoleColors(uint8_t colorMask);

	private:
		static KeyCode LastKeyCode;
		static int KeyRepeats;

		static MouseCode GetMouseExtra(WPARAM wp);
		static void OnKeyDown(Window& window, WPARAM wp);
		static void OnKeyUp(Window& window, WPARAM wp);
		static void OnTextType(Window& window, WPARAM wp);
		static void OnDoubleClick(Window& window, MouseCode button);
		static void OnMouseDown(Window& window, MouseCode button);
		static void OnMouseMove(Window& window, LPARAM lp);
		static void OnMouseScrollHorizontal(Window& window, WPARAM wp);
		static void OnMouseScrollVertical(Window& window, WPARAM wp);
		static void OnMouseUp(Window& window, MouseCode button);
		static void OnWindowClose(Window& window);
		static void OnWindowFocus(Window& window);
		static void OnWindowMove(Window& window, LPARAM lp);
		static void OnWindowSize(Window& window, LPARAM lp);
		static void OnWindowUnfocus(Window& window);

		API() = delete;
	};
}
