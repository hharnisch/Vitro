#include "_pch.h"
#include "WindowEvent.h"

namespace Vitro
{
	WindowEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << &WindowRef;
		return s.str();
	}

	Window& WindowEvent::GetWindow()
	{
		return WindowRef;
	}

	WindowEvent::WindowEvent(Window& window) : WindowRef(window)
	{}
}
