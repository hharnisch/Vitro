#include "_pch.h"
#include "WindowMoveEvent.h"

namespace Vitro
{
	WindowMoveEvent::WindowMoveEvent(uint64_t nativeID, int x, int y)
		: WindowEvent(nativeID), X(x), Y(y)
	{}

	WindowMoveEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << NativeID << ", " << X << ", " << Y;
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
