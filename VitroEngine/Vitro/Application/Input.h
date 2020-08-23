#pragma once

#include "Vitro/Application/ApplicationBase.h"
#include "Vitro/Application/KeyCode.h"
#include "Vitro/Application/MouseCode.h"
#include "Vitro/Math/Vector.h"

namespace Vitro
{
	class Input final
	{
		friend ApplicationBase;

	public:
		static inline bool IsDown(KeyCode key)
		{
			return KeyStates[key];
		}

		static inline bool IsDown(MouseCode button)
		{
			return MouseStates[button];
		}

		static inline Int2 GetMousePosition()
		{
			return MousePosition;
		}

		static inline int GetMouseX()
		{
			return MousePosition.X;
		}

		static inline int GetMouseY()
		{
			return MousePosition.Y;
		}

		Input() = delete;

	private:
		static inline std::unordered_map<KeyCode, bool> KeyStates;
		static inline std::unordered_map<MouseCode, bool> MouseStates;
		static inline Int2 MousePosition;
	};
}
