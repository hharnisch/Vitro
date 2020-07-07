#pragma once

#include "Vitro/Events/Mouse/MouseButtonEvent.h"

namespace Vitro
{
	// Event fired when releasing a mouse button.
	class MouseUpEvent : public MouseButtonEvent
	{
	public:
		$EventType(MouseUp);

		// Engine-internal constructor. Do NOT use in client application!
		MouseUpEvent(MouseCode button);
	};
}
