#include "_pch.h"
#include "TextTypeEvent.h"

namespace Vitro
{
	TextTypeEvent::TextTypeEvent(KeyCode key, std::string character)
		: KeyEvent(key), Character(character)
	{}

	TextTypeEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << Character << " (Key: " << ToString(Key) << ')';
		return s.str();
	}

	std::string TextTypeEvent::GetCharacter() const
	{
		return Character;
	}
}
