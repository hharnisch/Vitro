#include "_pch.h"
#include "WindowEvent.h"

namespace Vitro
{
	WindowEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << &WindowRef;
		return s.str();
	}

	Window& WindowEvent::GetWindow()
	{
		return WindowRef;
	}

	WindowEvent::WindowEvent(Window& window) : WindowRef(window)
	{}

	WindowCloseEvent::WindowCloseEvent(Window& window) : WindowEvent(window)
	{}

	WindowMoveEvent::WindowMoveEvent(Window& window, int x, int y) : WindowEvent(window), X(x), Y(y)
	{}

	WindowMoveEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << &WindowRef << ", " << X << ", " << Y;
		return s.str();
	}

	int WindowMoveEvent::GetX() const
	{
		return X;
	}

	int WindowMoveEvent::GetY() const
	{
		return Y;
	}

	WindowSizeEvent::WindowSizeEvent(Window& window, int width, int height)
		: WindowEvent(window), Width(width), Height(height)
	{}

	WindowSizeEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << &WindowRef << ", " << Width << ", " << Height;
		return s.str();
	}

	int WindowSizeEvent::GetWidth() const
	{
		return Width;
	}

	int WindowSizeEvent::GetHeight() const
	{
		return Height;
	}

	WindowFocusEvent::WindowFocusEvent(Window& window) : WindowEvent(window)
	{}

	WindowUnfocusEvent::WindowUnfocusEvent(Window& window) : WindowEvent(window)
	{}

	WindowOpenEvent::WindowOpenEvent(Window& window) : WindowEvent(window)
	{}
}
