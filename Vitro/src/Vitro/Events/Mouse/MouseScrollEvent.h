#pragma once

#include "Vitro/Events/Event.h"

namespace Vitro
{
	// Event fired when scrolling the mouse wheel.
	class MouseScrollEvent : public Event
	{
	public:
		$EventSource(EventSource::Input | EventSource::Mouse);
		$EventType(MouseScroll);

		// Engine-internal constructor. Do NOT use in client application!
		MouseScrollEvent(float xOffset, float yOffset);

		// The fraction of the detent that was scrolled sideways.
		float GetXOffset() const;

		// The fraction of the detent that was scrolled upwards.
		float GetYOffset() const;

		explicit operator std::string() const override;

	private:
		float XOffset;
		float YOffset;
	};
}
