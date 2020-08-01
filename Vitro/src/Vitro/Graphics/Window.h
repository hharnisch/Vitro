#pragma once

#if VTR_SYSTEM_WINDOWS
#include "Vitro/API/Windows/Window.h"
#endif

namespace Vitro
{
#if VTR_SYSTEM_WINDOWS
	typedef Windows::Window Window;
#else
#error Unsupported system.
#endif
}
