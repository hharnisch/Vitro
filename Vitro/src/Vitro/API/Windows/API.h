#pragma once

#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/KeyCode.h"
#include "Vitro/Events/MouseCode.h"

#include <Windows.h>

namespace Vitro::Windows
{
	class API
	{
	public:
		static constexpr auto WindowClassName = L"VITRO";

		static void Initialize(std::function<void(Window&, Event&)> dispatcher);
		static void SetConsoleColors(uint8_t colorMask);
		static std::wstring WidenChars(const std::string& s);
		static std::string NarrowChars(const std::wstring& ws);

		// Exists only for the Windows API to deliver messages.
		static LRESULT CALLBACK NotifyEngine(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

	private:
		static inline std::function<void(Window&, Event&)> Dispatcher;
		static inline KeyCode LastKeyCode;
		static inline int KeyRepeats;

		static void OnWindowMove(Window& window, LPARAM lp);
		static void OnWindowSize(Window& window, LPARAM lp);
		static void OnWindowFocus(Window& window);
		static void OnWindowUnfocus(Window& window);
		static void OnWindowClose(Window& window);
		static void OnWindowOpen(Window& window);
		static void OnKeyDown(Window& window, WPARAM wp);
		static void OnKeyUp(Window& window, WPARAM wp);
		static void OnTextType(Window& window, WPARAM wp);
		static void OnMouseMove(Window& window, LPARAM lp);
		static void OnMouseDown(Window& window, MouseCode button);
		static void OnMouseUp(Window& window, MouseCode button);
		static void OnDoubleClick(Window& window, MouseCode button);
		static void OnMouseScrollVertical(Window& window, WPARAM wp);
		static void OnMouseScrollHorizontal(Window& window, WPARAM wp);
		static MouseCode GetMouseExtra(WPARAM wp);

		API() = delete;
	};
}
