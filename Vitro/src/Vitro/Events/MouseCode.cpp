#include "_pch.h"
#include "MouseCode.h"

#define $ToString(x) case MouseCode::x: return #x

namespace Vitro
{
	std::string ToString(MouseCode button)
	{
		switch(button)
		{
			$ToString(None);
			$ToString(Mouse1);
			$ToString(Mouse2);
			$ToString(Wheel);
			$ToString(Extra1);
			$ToString(Extra2);
		}
		return "Unknown mouse button: " + static_cast<int>(button);
	}
}
