#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/VertexBuffer.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	template<typename V> using VertexBuffer = DirectX::VertexBuffer<V>;
#else
#error Unsupported graphics API.
#endif
}
