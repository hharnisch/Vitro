#include "_pch.h"
#include "Window.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/API.h"

#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>

namespace Vitro::Windows
{
	Window::Window(int width, int height, int x, int y, const std::string& title)
	{
		wchar_t* wstr = API::WidenChars(title.c_str());
		WindowHandle = CreateWindowExW(0, API::WindowClassName, wstr, WS_OVERLAPPEDWINDOW,
									   x, y, width, height, nullptr, nullptr,
									   API::InstanceHandle, nullptr);
		free(wstr);
		NativeID = (uint64_t)WindowHandle; // TODO: convert this to static_cast?

	#if $OPENGL
		DeviceContext = GetDC(WindowHandle);
		int pixelFormat = ChoosePixelFormat(DeviceContext, &API::PixelFormatDescriptor);
		SetPixelFormat(DeviceContext, pixelFormat, &API::PixelFormatDescriptor);
		OpenGLContext = wglCreateContext(DeviceContext);
		wglMakeCurrent(DeviceContext, OpenGLContext);
		glViewport(0, 0, width, height);
	#endif

		ImGui_ImplWin32_Init(WindowHandle);
	}

	Window::~Window()
	{
		DestroyWindow(WindowHandle);
	}

	std::string Window::GetTitle() const
	{
		int length = GetWindowTextLengthW(WindowHandle) + 1;
		wchar_t* wstr = static_cast<wchar_t*>(calloc(length, sizeof(wchar_t)));
		GetWindowTextW(WindowHandle, wstr, length);
		char* str = API::NarrowChars(wstr);
		free(wstr);

		std::string title(str);
		free(str);
		return title;
	}

	void Window::SetTitle(const std::string& title)
	{
		wchar_t* wstr = API::WidenChars(title.c_str());
		SetWindowTextW(WindowHandle, wstr);
		free(wstr);
	}

	int Window::GetWidth() const
	{
		RECT rect;
		GetWindowRect(WindowHandle, &rect);
		return rect.right - rect.left;
	}

	void Window::SetWidth(int width)
	{
		SetWindowPos(WindowHandle, nullptr, 0, 0, width, GetHeight(), SWP_NOMOVE | SWP_NOZORDER);
	}

	int Window::GetHeight() const
	{
		RECT rect;
		GetWindowRect(WindowHandle, &rect);
		return rect.bottom - rect.top;
	}

	void Window::SetHeight(int height)
	{
		SetWindowPos(WindowHandle, nullptr, 0, 0, GetWidth(), height, SWP_NOMOVE | SWP_NOZORDER);
	}

	int Window::GetX() const
	{
		RECT rect;
		GetWindowRect(WindowHandle, &rect);
		return rect.left;
	}

	void Window::SetX(int x)
	{
		SetWindowPos(WindowHandle, nullptr, x, GetY(), 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	int Window::GetY() const
	{
		RECT rect;
		GetWindowRect(WindowHandle, &rect);
		return rect.top;
	}

	void Window::SetY(int y)
	{
		SetWindowPos(WindowHandle, nullptr, GetX(), y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	void Window::Show()
	{
		ShowWindow(WindowHandle, SW_RESTORE);
	}

	void Window::Minimize()
	{
		CloseWindow(WindowHandle);
	}

	void Window::PrepareUpdate()
	{
	#if $OPENGL && $MULTIWINDOW
		wglMakeCurrent(DeviceContext, OpenGLContext);
	#endif

		MSG msg;
		while(PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) // TODO respond to WM_QUIT
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	void Window::FinalizeUpdate()
	{
		UpdateWindow(WindowHandle);
		SwapBuffers(DeviceContext);
	}
}
