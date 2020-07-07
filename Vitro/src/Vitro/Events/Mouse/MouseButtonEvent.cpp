#include "_pch.h"
#include "MouseButtonEvent.h"

namespace Vitro
{
	MouseCode MouseButtonEvent::GetButton() const
	{
		return Button;
	}

	MouseButtonEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << Button;
		return s.str();
	}

	MouseButtonEvent::MouseButtonEvent(MouseCode button) : Button(button)
	{
	}
}
