#pragma once

#include "Vitro/Events/Key/KeyCode.h"
#include "Vitro/Events/Mouse/MouseCode.h"

#include <Windows.h>

namespace Vitro::Windows
{
	class API
	{
	public:
		static constexpr auto WindowClassName = L"VITRO";
		static HINSTANCE InstanceHandle;
	#if $OPENGL
		static PIXELFORMATDESCRIPTOR PixelFormatDescriptor;
	#endif

		static void Initialize();

		// Exists only for the Windows API to deliver messages.
		static LRESULT CALLBACK NotifyEngine(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);

		// Result must be deallocated manually!
		static wchar_t* WidenChars(const char* str);

		// Result must be deallocated manually!
		static char* NarrowChars(const wchar_t* wstr);

		static void SetConsoleColors(uint8_t colorMask);
		static MouseCode GetExtraButton(WPARAM wp);
		static void OnKeyDown(WPARAM wp);
		static void OnKeyUp(WPARAM wp);
		static void OnTextType(WPARAM wp);
		static void OnDoubleClick(MouseCode button);
		static void OnMouseDown(MouseCode button);
		static void OnMouseMove(LPARAM lp);
		static void OnMouseScrollHorizontal(WPARAM wp);
		static void OnMouseScrollVertical(WPARAM wp);
		static void OnMouseUp(MouseCode button);
		static void OnWindowClose();
		static void OnWindowFocus();
		static void OnWindowMove(LPARAM lp);
		static void OnWindowSize(LPARAM lp);
		static void OnWindowUnfocus();

	private:
		static uint64_t MessageWindowID;
		static KeyCode LastKeyCode;
		static int KeyRepeats;

		API() = delete;
	};
}
