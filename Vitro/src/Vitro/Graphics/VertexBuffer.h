#pragma once

namespace Vitro
{
	class VertexBuffer
	{
	public:
		static VertexBuffer* New(size_t size);
		static VertexBuffer* New(size_t size, float* vertices);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void SetData(const void* data, size_t size) = 0;
	};
}
