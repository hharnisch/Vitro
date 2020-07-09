#include "_pch.h"
#include "MouseScrollEvent.h"

namespace Vitro
{
	MouseScrollEvent::MouseScrollEvent(float xOffset, float yOffset)
		: XOffset(xOffset), YOffset(yOffset)
	{
	}

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
