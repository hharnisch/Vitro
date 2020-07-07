#pragma once

#include "Vitro/Events/Mouse/MouseButtonEvent.h"

namespace Vitro
{
	// Event fired when pressing down a mouse button.
	class MouseDownEvent : public MouseButtonEvent
	{
	public:
		$EventType(MouseDown);

		// Engine-internal constructor. Do NOT use in client application!
		MouseDownEvent(MouseCode button);
	};
}
