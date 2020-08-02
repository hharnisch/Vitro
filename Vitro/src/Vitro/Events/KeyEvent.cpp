#include "_pch.h"
#include "KeyEvent.h"

namespace Vitro
{
	KeyCode KeyEvent::GetKeyCode() const
	{
		return Key;
	}

	KeyEvent::KeyEvent(KeyCode key) : Key(key)
	{}

	KeyDownEvent::KeyDownEvent(KeyCode key, int repeats) : KeyEvent(key), Repeats(repeats)
	{}

	KeyDownEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << ToString(Key) << " (Repeats: " << Repeats << ")";
		return s.str();
	}

	int KeyDownEvent::GetRepeats() const
	{
		return Repeats;
	}

	KeyUpEvent::KeyUpEvent(KeyCode key) : KeyEvent(key)
	{}

	KeyUpEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << ToString(Key);
		return s.str();
	}

	TextTypeEvent::TextTypeEvent(KeyCode key, std::string character)
		: KeyEvent(key), Character(character)
	{}

	TextTypeEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << Character << " (Key: " << ToString(Key) << ")";
		return s.str();
	}

	std::string TextTypeEvent::GetCharacter() const
	{
		return Character;
	}
}
