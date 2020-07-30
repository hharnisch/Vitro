#pragma once

#include "Vitro/Graphics/VertexBuffer.h"

namespace Vitro::DirectX
{
	class VertexBuffer : public Vitro::VertexBuffer
	{
	public:
		VertexBuffer(size_t size);
		VertexBuffer(size_t size, float* vertices);

		void Bind() const override;
		void Unbind() const override;
		void SetData(const void* data, size_t size) override;
	};
}
