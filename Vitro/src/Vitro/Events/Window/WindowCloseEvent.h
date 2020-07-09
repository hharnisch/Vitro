#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowEvent.h"

namespace Vitro
{
	// Event fired when closing a window.
	class WindowCloseEvent : public WindowEvent
	{
	public:
		$EventType(WindowClose);

		// Engine-internal constructor. Do NOT use in client application!
		WindowCloseEvent(uint64_t nativeID);
	};
}
