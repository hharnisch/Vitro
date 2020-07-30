#include "_pch.h"
#include "VertexBuffer.h"

#include "Vitro/API/DirectX/VertexBuffer.h"

namespace Vitro
{
	VertexBuffer* VertexBuffer::New(size_t size)
	{
	#if $DIRECTX
		return new DirectX::VertexBuffer(size);
	#else
	#error Unsupported graphics API.
	#endif
	}

	VertexBuffer* VertexBuffer::New(size_t size, float* vertices)
	{
	#if $DIRECTX
		return new DirectX::VertexBuffer(size, vertices);
	#else
	#error Unsupported graphics API.
	#endif
	}
}
