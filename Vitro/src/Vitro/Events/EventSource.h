#pragma once

#include "Vitro/Math/Bit.h"

namespace Vitro
{
	// Indicates the device type or source associated with an event type.
	enum class EventSource : unsigned char
	{
		None		= 0,			// Never sent by an event. Only for variable initialization.
		App			= TurnOnBit(0),
		Input		= TurnOnBit(1),
		Keyboard	= TurnOnBit(2),
		Mouse		= TurnOnBit(3),
		MouseButton	= TurnOnBit(4)
	};

	// For using this enum as a bitmask.
	uint8_t operator&(EventSource s1, EventSource s2);
	EventSource operator|(EventSource s1, EventSource s2);
}
