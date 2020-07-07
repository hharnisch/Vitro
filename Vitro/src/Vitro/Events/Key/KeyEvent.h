#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Key/KeyCode.h"

namespace Vitro
{
	// Superclass for all keyboard events.
	class KeyEvent : public Event
	{
	public:
		$EventSource(EventSource::Input | EventSource::Keyboard);

		KeyCode GetKeyCode() const;

	protected:
		KeyCode Key;

		KeyEvent(KeyCode key);
	};
}
