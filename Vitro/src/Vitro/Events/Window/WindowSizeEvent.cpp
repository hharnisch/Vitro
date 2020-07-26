#include "_pch.h"
#include "WindowSizeEvent.h"

namespace Vitro
{
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
}
