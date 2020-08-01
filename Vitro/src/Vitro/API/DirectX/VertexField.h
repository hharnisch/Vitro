#pragma once

#include "Vitro/API/Base/VertexField.h"
#include "Vitro/Graphics/VertexFieldType.h"

#include <d3d11_4.h>

namespace Vitro::DirectX
{
	class VertexField : public Base::VertexField
	{
	public:
		static constexpr auto Color		= "COLOR";
		static constexpr auto Position	= "POSITION";
		static constexpr auto TexCoord	= "TEXCOORD";

		D3D11_INPUT_ELEMENT_DESC Descriptor;

		VertexField(const char name[], uint32_t index, VertexFieldType type, uint32_t offset);
	};
}
