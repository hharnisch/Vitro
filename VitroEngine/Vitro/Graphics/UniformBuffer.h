#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/UniformBuffer.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	template<typename V> using UniformBuffer = DirectX::UniformBuffer<V>;
#else
#error Unsupported graphics API.
#endif
}
