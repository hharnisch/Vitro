#pragma once

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/VertexField.h"
#endif

namespace Vitro
{
#if VTR_API_DIRECTX
	typedef DirectX::VertexField VertexField;
#else
#error Unsupported graphics API.
#endif
}
