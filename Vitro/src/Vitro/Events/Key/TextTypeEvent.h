#pragma once

#include "Vitro/Events/Key/KeyEvent.h"

namespace Vitro
{
	// Event fired when receiving text character input from the keyboard.
	class TextTypeEvent : public KeyEvent
	{
	public:
		$EventType(TextType);

		// Engine-internal constructor. Do NOT use in client application!
		TextTypeEvent(KeyCode key, std::string character);

		std::string GetCharacter() const;

		explicit operator std::string() const override;

	private:
		std::string Character;
	};
}
