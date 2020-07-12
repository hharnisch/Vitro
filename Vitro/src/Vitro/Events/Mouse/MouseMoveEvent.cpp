#include "_pch.h"
#include "MouseMoveEvent.h"

namespace Vitro
{
	MouseMoveEvent::MouseMoveEvent(int x, int y) : X(x), Y(y)
	{}

	MouseMoveEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << X << ", " << Y;
		return s.str();
	}

	int MouseMoveEvent::GetX() const
	{
		return X;
	}

	int MouseMoveEvent::GetY() const
	{
		return Y;
	}
}
