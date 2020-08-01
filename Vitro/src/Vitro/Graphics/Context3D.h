#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/Context3D.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	typedef DirectX::Context3D Context3D;
#else
#error Unsupported graphics API.
#endif
}
