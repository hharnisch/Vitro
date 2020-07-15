#include "_pch.h"
#include "Input.h"

namespace Vitro
{
	std::unordered_map<KeyCode, bool> Input::KeyStates;
	std::unordered_map<MouseCode, bool> Input::MouseStates;
	Int2 Input::MousePosition;

	bool Input::IsKeyDown(KeyCode code)
	{
		return KeyStates[code];
	}

	bool Input::IsMouseDown(MouseCode button)
	{
		return MouseStates[button];
	}

	Int2 Input::GetMousePosition()
	{
		return MousePosition;
	}

	int Input::GetMouseX()
	{
		return MousePosition.X;
	}

	int Input::GetMouseY()
	{
		return MousePosition.Y;
	}
}
