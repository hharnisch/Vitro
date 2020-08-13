#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/VertexShader.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	typedef DirectX::VertexShader VertexShader;
#else
#error Unsupported graphics API.
#endif
}
