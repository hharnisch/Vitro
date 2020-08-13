#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/IndexBuffer.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	typedef DirectX::IndexBuffer IndexBuffer;
#else
#error Unsupported graphics API.
#endif
}
