#pragma once

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
		static LRESULT CALLBACK NotifyEngine(HWND window, UINT message, WPARAM wp, LPARAM lp);

		static void SetConsoleColors(uint8_t colorMask);

		// Result must be deallocated manually!
		static wchar_t* WidenChars(const char* str);

		// Result must be deallocated manually!
		static char* NarrowChars(const wchar_t* wstr);

	private:
		static bool IsInitialized;
	};
}
