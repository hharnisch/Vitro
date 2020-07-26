#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowEvent.h"

namespace Vitro
{
	// Event fired when a window gets focus.
	class WindowFocusEvent : public WindowEvent
	{
	public:
		$EventType(WindowFocus);

		// Engine-internal constructor. Do NOT use in client application!
		WindowFocusEvent(Window& window);
	};
}
