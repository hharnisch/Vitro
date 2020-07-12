#pragma once

#include "Vitro/Events/Event.h"

namespace Vitro
{
	// Event fired when moving the mouse.
	class MouseMoveEvent : public Event
	{
	public:
		$EventSource(EventSource::Input | EventSource::Mouse);
		$EventType(MouseMove);

		// Engine-internal constructor. Do NOT use in client application!
		MouseMoveEvent(int x, int y);

		explicit operator std::string() const override;

		int GetX() const;
		int GetY() const;

	private:
		int X;
		int Y;
	};
}
