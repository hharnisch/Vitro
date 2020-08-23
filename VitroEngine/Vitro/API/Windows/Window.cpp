#include "_pch.h"
#include "Window.h"

#include "Vitro/API/Windows/ApplicationBase.h"
#include "Vitro/Graphics/Renderer3D.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>

namespace Vitro::Windows
{
	Window::Window(int width, int height, int x, int y, const std::string& title)
	{
		auto wstr = ApplicationBase::WidenChars(title);
		NativeHandle = CreateWindowExW(0, ApplicationBase::WindowClassName, wstr.c_str(),
									   WS_OVERLAPPEDWINDOW, x, y, width, height, nullptr, nullptr,
									   nullptr, nullptr);
		AssertCritical(NativeHandle, "Could not create window.");
		SetWindowLongPtr(NativeHandle, 0, reinterpret_cast<LONG_PTR>(this));
		Renderer = Ref<Renderer3D>::New(NativeHandle, GetViewportWidth(), GetViewportHeight());

		ImGui_ImplWin32_Init(NativeHandle);
	}

	Window::Window(Window&& other) noexcept :
		Vitro::Window(std::move(other)), NativeHandle(std::exchange(other.NativeHandle, nullptr))
	{}

	Window::~Window()
	{
		DestroyWindow(NativeHandle);
		ImGui_ImplWin32_Shutdown();
	}

	Window& Window::operator=(Window&& other) noexcept
	{
		Vitro::Window::operator=(std::move(other));
		std::swap(NativeHandle, other.NativeHandle);
		return *this;
	}

	int Window::GetWidth() const
	{
		RECT rect;
		GetWindowRect(NativeHandle, &rect);
		return rect.right - rect.left;
	}

	void Window::SetWidth(int width)
	{
		SetWindowPos(NativeHandle, nullptr, 0, 0, width, GetHeight(), SWP_NOMOVE | SWP_NOZORDER);
	}

	int Window::GetViewportWidth() const
	{
		RECT rect;
		GetClientRect(NativeHandle, &rect);
		return rect.right - rect.left;
	}

	int Window::GetHeight() const
	{
		RECT rect;
		GetWindowRect(NativeHandle, &rect);
		return rect.bottom - rect.top;
	}

	void Window::SetHeight(int height)
	{
		SetWindowPos(NativeHandle, nullptr, 0, 0, GetWidth(), height, SWP_NOMOVE | SWP_NOZORDER);
	}

	int Window::GetViewportHeight() const
	{
		RECT rect;
		GetClientRect(NativeHandle, &rect);
		return rect.bottom - rect.top;
	}

	int Window::GetX() const
	{
		RECT rect;
		GetWindowRect(NativeHandle, &rect);
		return rect.left;
	}

	void Window::SetX(int x)
	{
		SetWindowPos(NativeHandle, nullptr, x, GetY(), 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	int Window::GetY() const
	{
		RECT rect;
		GetWindowRect(NativeHandle, &rect);
		return rect.top;
	}

	void Window::SetY(int y)
	{
		SetWindowPos(NativeHandle, nullptr, GetX(), y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	std::string Window::GetTitle() const
	{
		int length = GetWindowTextLengthW(NativeHandle);
		std::wstring title(length, 0);
		GetWindowTextW(NativeHandle, &title[0], length + 1);
		return ApplicationBase::NarrowChars(title);
	}

	void Window::SetTitle(const std::string& title)
	{
		auto wstr = ApplicationBase::WidenChars(title);
		SetWindowTextW(NativeHandle, wstr.c_str());
	}

	void* Window::GetNativeHandle() const
	{
		return NativeHandle;
	}

	void Window::Open()
	{
		ShowWindow(NativeHandle, SW_RESTORE);
	}

	void Window::Close()
	{
		ShowWindow(NativeHandle, SW_HIDE);
	}

	void Window::Maximize()
	{
		ShowWindow(NativeHandle, SW_MAXIMIZE);
	}

	void Window::Minimize()
	{
		CloseWindow(NativeHandle);
	}

	void Window::TrapCursor(bool shouldTrap)
	{
		if(shouldTrap)
		{
			RECT rect;
			GetWindowRect(NativeHandle, &rect);
			ClipCursor(&rect);
		}
		else
			ClipCursor(nullptr);
	}
}
