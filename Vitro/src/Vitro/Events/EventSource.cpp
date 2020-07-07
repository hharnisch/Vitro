#include "_pch.h"
#include "EventSource.h"

namespace Vitro
{
	uint8_t operator&(EventSource s1, EventSource s2)
	{
		return static_cast<uint8_t>(s1) & static_cast<uint8_t>(s2);
	}

	EventSource operator|(EventSource s1, EventSource s2)
	{
		return static_cast<EventSource>(static_cast<uint8_t>(s1) | static_cast<uint8_t>(s2));
	}
}
