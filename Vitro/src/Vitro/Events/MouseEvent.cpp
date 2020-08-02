#include "_pch.h"
#include "MouseEvent.h"

namespace Vitro
{
	MouseEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << ToString(Button);
		return s.str();
	}

	MouseCode MouseEvent::GetButton() const
	{
		return Button;
	}

	MouseEvent::MouseEvent(MouseCode button) : Button(button)
	{}

	MouseMoveEvent::MouseMoveEvent(int x, int y) : MouseEvent(MouseCode::None), X(x), Y(y)
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

	MouseDownEvent::MouseDownEvent(MouseCode button) : MouseEvent(button)
	{}

	MouseUpEvent::MouseUpEvent(MouseCode button) : MouseEvent(button)
	{}

	DoubleClickEvent::DoubleClickEvent(MouseCode button) : MouseEvent(button)
	{}

	MouseScrollEvent::MouseScrollEvent(float xOffset, float yOffset)
		: MouseEvent(MouseCode::Wheel), XOffset(xOffset), YOffset(yOffset)
	{}

	MouseScrollEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << XOffset << ", " << YOffset;
		return s.str();
	}

	float MouseScrollEvent::GetXOffset() const
	{
		return XOffset;
	}

	float MouseScrollEvent::GetYOffset() const
	{
		return YOffset;
	}
}
