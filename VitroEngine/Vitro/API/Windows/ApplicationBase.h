#pragma once

#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/KeyCode.h"
#include "Vitro/Events/MouseCode.h"
#include "Vitro/Events/WindowEvent.h"

#include <windows.h>

namespace Vitro::Windows
{
	class ApplicationBase
	{
	public:
		static constexpr auto WindowClassName = L"VITRO";

		ApplicationBase();

		static std::wstring WidenChars(const std::string& s);
		static std::string NarrowChars(const std::wstring& ws);

		void SetConsoleColors(uint8_t colorMask);

	protected:
		virtual void EraseWindow(Window& window) = 0;
		virtual void EmplaceWindow(Window& window) = 0;

		void PollEvents();

	private:
		KeyCode LastKeyCode = KeyCode::None;
		int KeyRepeats = 0;

		// Exists only for the Windows API to deliver messages.
		static LRESULT CALLBACK ReceiveMessages(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

		LRESULT ForwardMessages(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);
		void OnWindowMove(Window& window, LPARAM lp);
		void OnWindowSize(Window& window, LPARAM lp);
		void OnWindowFocus(Window& window);
		void OnWindowUnfocus(Window& window);
		void OnWindowClose(Window& window);
		void OnWindowOpen(Window& window);
		void OnRawInput(Window& window, LPARAM lp);
		void OnKeyDown(Window& window, WPARAM wp);
		void OnKeyUp(Window& window, WPARAM wp);
		void OnKeyText(Window& window, WPARAM wp);
		void OnMouseMove(Window& window, LPARAM lp);
		void OnMouseDown(Window& window, MouseCode button);
		void OnMouseUp(Window& window, MouseCode button);
		void OnDoubleClick(Window& window, MouseCode button);
		void OnMouseScrollVertical(Window& window, WPARAM wp);
		void OnMouseScrollHorizontal(Window& window, WPARAM wp);
		MouseCode GetMouseExtra(WPARAM wp);
	};
}
