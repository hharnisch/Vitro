#pragma once

#if VTR_SYSTEM_WINDOWS
#include "Vitro/API/Windows/ApplicationBase.h"
#endif

namespace Vitro
{
#if VTR_SYSTEM_WINDOWS
	typedef Windows::ApplicationBase ApplicationBase;
#else
#error Unsupported system.
#endif
}
