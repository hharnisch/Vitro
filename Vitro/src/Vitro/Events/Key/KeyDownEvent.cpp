#include "_pch.h"
#include "KeyDownEvent.h"

namespace Vitro
{
	KeyDownEvent::KeyDownEvent(KeyCode key, int repeats) : KeyEvent(key), Repeats(repeats)
	{}

	KeyDownEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << ToString(Key) << " (Repeats: " << Repeats << ')';
		return s.str();
	}

	int KeyDownEvent::GetRepeats() const
	{
		return Repeats;
	}
}
