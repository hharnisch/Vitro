#include "_pch.h"
#include "KeyEvent.h"

namespace Vitro
{
	KeyCode KeyEvent::GetKeyCode() const
	{
		return Key;
	}

	KeyEvent::KeyEvent(KeyCode key) : Key(key)
	{
	}
}
