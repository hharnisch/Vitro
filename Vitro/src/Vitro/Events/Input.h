#pragma once

#include "Vitro/API/Windows/API.h"
#include "Vitro/Events/KeyCode.h"
#include "Vitro/Events/MouseCode.h"
#include "Vitro/Math/Vector.h"

namespace Vitro
{
	class Input
	{
		friend class Windows::API;

	public:
		static bool IsKeyDown(KeyCode key);
		static bool IsMouseDown(MouseCode button);
		static Int2 GetMousePosition();
		static int GetMouseX();
		static int GetMouseY();

	private:
		static std::unordered_map<KeyCode, bool> KeyStates;
		static std::unordered_map<MouseCode, bool> MouseStates;
		static Int2 MousePosition;

		Input() = delete;
	};
}
