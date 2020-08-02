#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowEvent.h"

namespace Vitro
{
	// Event fired when opening a window.
	class WindowOpenEvent : public WindowEvent
	{
	public:
		$EventType(WindowOpen);

		// Engine-internal constructor. Do NOT use in client application!
		WindowOpenEvent(Window& window);
	};
}
