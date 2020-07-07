#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Mouse/MouseCode.h"

namespace Vitro
{
	// Superclass for all mouse button events.
	class MouseButtonEvent : public Event
	{
	public:
		$EventSource(EventSource::Input | EventSource::MouseButton);

		MouseCode GetButton() const;

		explicit operator std::string() const override;

	protected:
		MouseCode Button;

		MouseButtonEvent(MouseCode button);
	};
}
