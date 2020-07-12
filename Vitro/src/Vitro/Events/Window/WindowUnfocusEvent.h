#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowEvent.h"

namespace Vitro
{
	// Event fired when a window loses focus.
	class WindowUnfocusEvent : public WindowEvent
	{
	public:
		$EventType(WindowUnfocus);

		// Engine-internal constructor. Do NOT use in client application!
		WindowUnfocusEvent(uint64_t nativeID);
	};
}
