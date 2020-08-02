#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/KeyCode.h"

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

	// Event fired when releasing a keyboard key.
	class KeyUpEvent : public KeyEvent
	{
	public:
		$EventType(KeyUp);

		// Engine-internal constructor. Do NOT use in client application!
		KeyUpEvent(KeyCode key);

		explicit operator std::string() const override;
	};

	// Event fired when receiving text character input from the keyboard.
	class TextTypeEvent : public KeyEvent
	{
	public:
		$EventType(TextType);

		// Engine-internal constructor. Do NOT use in client application!
		TextTypeEvent(KeyCode key, std::string character);

		explicit operator std::string() const override;

		std::string GetCharacter() const;

	private:
		std::string Character;
	};
}
