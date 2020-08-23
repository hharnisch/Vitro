#include "_pch.h"
#include "VertexBuffer.h"

#include "Vitro/API/DirectX/RHI.h"

namespace Vitro::DirectX
{
	VertexBuffer::VertexBuffer(const void* vertices, size_t stride, size_t size) :
		Stride(static_cast<uint32_t>(stride)), Size(static_cast<uint32_t>(size))
	{
		D3D11_BUFFER_DESC bd {0};
		bd.ByteWidth	= Size;
		bd.Usage		= D3D11_USAGE_DEFAULT;
		bd.BindFlags	= D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA srd {0};
		srd.pSysMem = vertices;

		auto res = RHI::Device->CreateBuffer(&bd, &srd, &Buffer);
		AssertCritical(SUCCEEDED(res), "Could not create vertex buffer.");
	}

	void VertexBuffer::Bind(VertexTopology vt) const
	{
		UINT offset = 0;
		RHI::Context->IASetVertexBuffers(0, 1, Buffer.GetAddressOf(), &Stride, &offset);
		RHI::Context->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(vt));
	}

	void VertexBuffer::Update(const void* vertices) const
	{
		RHI::Context->UpdateSubresource(Buffer.Get(), 0, nullptr, vertices, 0, 0);
	}
}
