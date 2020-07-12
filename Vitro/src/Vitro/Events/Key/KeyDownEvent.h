#pragma once

#include "Vitro/Events/Key/KeyEvent.h"

namespace Vitro
{
	// Event fired when pressing down a keyboard key.
	class KeyDownEvent : public KeyEvent
	{
	public:
		$EventType(KeyDown);

		// Engine-internal constructor. Do NOT use in client application!
		KeyDownEvent(KeyCode key, int repetitions);

		explicit operator std::string() const override;

		int GetRepeats() const;

	private:
		int Repeats;
	};
}
