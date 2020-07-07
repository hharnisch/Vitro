#include "_pch.h"
#include "KeyDownEvent.h"

namespace Vitro
{
	KeyDownEvent::KeyDownEvent(KeyCode key, int repeats) : KeyEvent(key), Repeats(repeats)
	{
	}

	int KeyDownEvent::GetRepeats() const
	{
		return Repeats;
	}

	KeyDownEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << Key << " (Repeats: " << Repeats << ')';
		return s.str();
	}
}
