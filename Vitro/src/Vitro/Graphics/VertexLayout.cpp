#include "_pch.h"
#include "VertexLayout.h"

namespace Vitro
{
	VertexLayout::VertexLayout(const std::initializer_list<VertexField>& fields) :
		Fields(fields), Stride(0)
	{
		uint32_t offset = 0;
		for(auto& field : Fields)
		{
			field.Offset = offset;
			offset += field.StorageSize;
			Stride += field.StorageSize;
		}
	}

	const VertexField& VertexLayout::operator[](size_t index) const
	{
		return Fields[index];
	}

	size_t VertexLayout::Count() const
	{
		return Fields.size();
	}
}
