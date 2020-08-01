#include "_pch.h"
#include "VertexField.h"

namespace Vitro::DirectX
{
	VertexField::VertexField(const char name[], uint32_t index, VertexFieldType type,
							 uint32_t offset)
	{
		Descriptor.SemanticName			= name;
		Descriptor.SemanticIndex		= index;
		Descriptor.Format				= static_cast<DXGI_FORMAT>(type);
		Descriptor.InputSlot			= 0;
		Descriptor.AlignedByteOffset	= offset;
		Descriptor.InputSlotClass		= D3D11_INPUT_PER_VERTEX_DATA;
		Descriptor.InstanceDataStepRate	= 0;
	}
}
