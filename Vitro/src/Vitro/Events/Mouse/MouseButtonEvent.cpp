#include "_pch.h"
#include "MouseButtonEvent.h"

namespace Vitro
{
	MouseButtonEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << ToString(Button);
		return s.str();
	}

	MouseCode MouseButtonEvent::GetButton() const
	{
		return Button;
	}

	MouseButtonEvent::MouseButtonEvent(MouseCode button) : Button(button)
	{}
}
