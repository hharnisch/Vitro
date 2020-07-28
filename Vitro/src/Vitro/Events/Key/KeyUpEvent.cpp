#include "_pch.h"
#include "KeyUpEvent.h"

namespace Vitro
{
	KeyUpEvent::KeyUpEvent(KeyCode key) : KeyEvent(key)
	{}

	KeyUpEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << ToString(Key);
		return s.str();
	}
}
