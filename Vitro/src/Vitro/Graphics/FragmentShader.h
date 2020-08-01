#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/FragmentShader.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	typedef DirectX::FragmentShader FragmentShader;
#else
#error Unsupported graphics API.
#endif
}
