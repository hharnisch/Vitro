#include "_pch.h"
#include "Window.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Events/Window//WindowFocusEvent.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>

namespace Vitro::Windows
{
	Window::Window(int width, int height, int x, int y, const std::string& title)
		: Width(width), Height(height), X(x), Y(y), Title(title)
	{}

	Window::~Window()
	{
		Close();
	}

	int Window::GetWidth() const
	{
		return Width;
	}

	void Window::SetWidth(int width)
	{
		if(width < 1)
			return;
		Width = width;
		SetWindowPos(NativeHandle, nullptr, 0, 0, Width, Height, SWP_NOMOVE | SWP_NOZORDER);
	}

	int Window::GetHeight() const
	{
		return Height;
	}

	void Window::SetHeight(int height)
	{
		if(height < 1)
			return;
		Height = height;
		SetWindowPos(NativeHandle, nullptr, 0, 0, Width, Height, SWP_NOMOVE | SWP_NOZORDER);
	}

	int Window::GetX() const
	{
		return X;
	}

	void Window::SetX(int x)
	{
		X = x;
		SetWindowPos(NativeHandle, nullptr, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	int Window::GetY() const
	{
		return Y;
	}

	void Window::SetY(int y)
	{
		Y = y;
		SetWindowPos(NativeHandle, nullptr, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	std::string Window::GetTitle() const
	{
		return Title;
	}

	void Window::SetTitle(const std::string& title)
	{
		Title = title;
		wchar_t* wstr = API::WidenChars(title.c_str());
		SetWindowTextW(NativeHandle, wstr);
		free(wstr);
	}

	void Window::Open()
	{
		wchar_t* wstr = API::WidenChars(Title.c_str());
		NativeHandle = CreateWindowExW(0, API::WindowClassName, wstr, WS_OVERLAPPEDWINDOW,
									   X, Y, Width, Height, nullptr, nullptr,
									   API::InstanceHandle, nullptr);
		free(wstr);
		SetWindowLongPtr(NativeHandle, 0, reinterpret_cast<LONG_PTR>(this));

		Engine::OnWindowOpen(this);
		ImGui_ImplWin32_Init(NativeHandle);
		ShowWindow(NativeHandle, SW_RESTORE);
	}

	void Window::Close()
	{
		DestroyWindow(NativeHandle);
	}

	void Window::Maximize()
	{
		ShowWindow(NativeHandle, SW_MAXIMIZE);
	}

	void Window::Minimize()
	{
		CloseWindow(NativeHandle);
	}

	void Window::UpdatePlatform()
	{
		UpdateWindow(NativeHandle);

		MSG msg;
		while(PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) // TODO respond to WM_QUIT
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	void Window::OnPlatformEvent(Event& e)
	{}
}
