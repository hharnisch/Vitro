#pragma once

namespace Vitro
{
	enum class MouseCode : uint8_t
	{
		None		= 0,	// Never sent by an event. Only for variable initialization.
		Mouse1		= 1,	// The primary mouse button, usually the left physical button.
		Mouse2		= 2,	// The secondary mouse button, usually the right physical button.
		Wheel		= 3,	// The mouse wheel or middle mouse button.
		Extra1		= 4,	// The first additional mouse button.
		Extra2		= 5		// The second additional mouse button.
	};

	std::string ToString(MouseCode button);
}
