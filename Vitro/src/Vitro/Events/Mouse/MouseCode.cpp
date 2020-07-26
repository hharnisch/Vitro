#include "_pch.h"
#include "MouseCode.h"

#define $ToString(x) case MouseCode::x: return os << #x

namespace Vitro
{
	std::ostream& operator<<(std::ostream& os, MouseCode button)
	{
		switch(button)
		{
			$ToString(Mouse1);
			$ToString(Mouse2);
			$ToString(Wheel);
			$ToString(Extra1);
			$ToString(Extra2);
		}
		return os << "Unknown mouse button: " << static_cast<int>(button);
	}
}
