#include "_pch.h"
#include "Window.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Graphics/Renderer3D.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>

namespace Vitro::Windows
{
	Window::Window(int width, int height, int x, int y, const std::string& title) :
		Width(width), Height(height), X(x), Y(y), Title(title), NativeHandle(nullptr)
	{}

	Window::Window(Window&& other) noexcept :
		Base::Window(std::move(other)),
		Width(other.Width), Height(other.Height), X(other.X), Y(other.Y),
		Title(std::move(other.Title)),
		NativeHandle(std::exchange(other.NativeHandle, nullptr))
	{}

	Window::~Window()
	{
		Close();
	}

	Window& Window::operator=(Window&& other) noexcept
	{
		Base::Window::operator=(std::move(other));
		Width = other.Width;
		Height = other.Height;
		X = other.X;
		Y = other.Y;
		Title = std::move(other.Title);
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

	void* Window::GetNativeHandle() const
	{
		return NativeHandle;
	}

	void Window::Open()
	{
		auto wstr = API::WidenChars(Title);
		NativeHandle = CreateWindowExW(0, API::WindowClassName, wstr.c_str(), WS_OVERLAPPEDWINDOW,
									   X, Y, Width, Height, nullptr, nullptr, nullptr, nullptr);
		SetWindowLongPtr(NativeHandle, 0, reinterpret_cast<LONG_PTR>(this));

		Renderer = std::make_shared<Renderer3D>(*this);

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

	void Window::PollEvents()
	{
		MSG msg;
		while(PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	void Window::PlatformOnEvent(Event& e)
	{
		e.Dispatch<WindowSizeEvent>([this](WindowSizeEvent& e)
		{
			Width = e.GetWidth();
			Height = e.GetHeight();
			return false;
		});
		e.Dispatch<WindowMoveEvent>([this](WindowMoveEvent& e)
		{
			X = e.GetX();
			Y = e.GetY();
			return false;
		});
	}
}
