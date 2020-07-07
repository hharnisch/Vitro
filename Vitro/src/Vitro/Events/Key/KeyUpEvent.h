#pragma once

#include "Vitro/Events/Key/KeyEvent.h"

namespace Vitro
{
	// Event fired when releasing a keyboard key.
	class KeyUpEvent : public KeyEvent
	{
	public:
		$EventType(KeyUp);

		// Engine-internal constructor. Do NOT use in client application!
		KeyUpEvent(KeyCode key);

		explicit operator std::string() const override;
	};
}
