#pragma once

#include "Vitro/Events/Mouse/MouseButtonEvent.h"

namespace Vitro
{
	// Event fired when double-clicking a mouse button.
	class DoubleClickEvent : public MouseButtonEvent
	{
	public:
		$EventType(DoubleClick);

		// Engine-internal constructor. Do NOT use in client application!
		DoubleClickEvent(MouseCode button);
	};
}
