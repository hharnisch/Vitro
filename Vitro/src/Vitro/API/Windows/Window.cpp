#include "_pch.h"
#include "Window.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Graphics/Context3D.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>

namespace Vitro::Windows
{
	Window::Window(int width, int height, int x, int y, const std::string& title) :
		Base::Window(width, height, x, y, title)
	{}

	Window::Window(Window&& other) noexcept : Base::Window(std::move(other)),
		NativeHandle(std::exchange(other.NativeHandle, nullptr))
	{}

	Window::~Window()
	{
		Close();
	}

	Window& Window::operator=(Window&& other) noexcept
	{
		Base::Window::operator=(std::move(other));
		std::swap(NativeHandle, other.NativeHandle);
		return *this;
	}

	int Window::GetWidth() const
	{
		return Width;
	}

	void Window::SetWidth(int width)
	{
		if(SetWindowPos(NativeHandle, nullptr, 0, 0, Width, Height, SWP_NOMOVE | SWP_NOZORDER))
			Width = width;
	}

	int Window::GetHeight() const
	{
		return Height;
	}

	void Window::SetHeight(int height)
	{
		if(SetWindowPos(NativeHandle, nullptr, 0, 0, Width, Height, SWP_NOMOVE | SWP_NOZORDER))
			Height = height;
	}

	int Window::GetX() const
	{
		return X;
	}

	void Window::SetX(int x)
	{
		if(SetWindowPos(NativeHandle, nullptr, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER))
			X = x;
	}

	int Window::GetY() const
	{
		return Y;
	}

	void Window::SetY(int y)
	{
		if(SetWindowPos(NativeHandle, nullptr, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER))
			Y = y;
	}

	std::string Window::GetTitle() const
	{
		return Title;
	}

	void Window::SetTitle(const std::string& title)
	{
		auto wstr = API::WidenChars(title);
		if(SetWindowTextW(NativeHandle, wstr.c_str()))
			Title = title;
	}

	HWND Window::GetNativeHandle()
	{
		return NativeHandle;
	}

	void Window::Open()
	{
		auto wstr = API::WidenChars(Title);
		NativeHandle = CreateWindowExW(0, API::WindowClassName, wstr.c_str(), WS_OVERLAPPEDWINDOW,
									   X, Y, Width, Height, nullptr, nullptr, API::ModuleHandle,
									   nullptr);
		SetWindowLongPtr(NativeHandle, 0, reinterpret_cast<LONG_PTR>(this));

		GraphicsContext3D = std::make_unique<Context3D>(this);
		GraphicsContext3D->SetViewport(Width, Height, 0, 0);

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
		MSG msg;
		while(PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}
}
