#include "_pch.h"
#include "VertexField.h"

namespace Vitro::DirectX
{
	VertexField::VertexField(const char name[], uint32_t index, VertexFieldType type,
							 uint32_t offset) : Descriptor{0}
	{
		Descriptor.SemanticName			= name;
		Descriptor.SemanticIndex		= index;
		Descriptor.Format				= static_cast<DXGI_FORMAT>(type);
		Descriptor.AlignedByteOffset	= offset;
	}
}
