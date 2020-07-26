#include "_pch.h"
#include "WindowMoveEvent.h"

namespace Vitro
{
	WindowMoveEvent::WindowMoveEvent(Window& window, int x, int y)
		: WindowEvent(window), X(x), Y(y)
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
}
