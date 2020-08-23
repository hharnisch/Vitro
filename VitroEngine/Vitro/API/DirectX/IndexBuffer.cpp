#include "_pch.h"
#include "IndexBuffer.h"

#include "Vitro/API/DirectX/RHI.h"

namespace Vitro::DirectX
{
	IndexBuffer::IndexBuffer(const HeapArray<uint32_t>& indices) :
		IndexBuffer(indices.Raw(), indices.Count())
	{}

	IndexBuffer::IndexBuffer(const uint32_t indices[], size_t count) :
		IndexCount(static_cast<uint32_t>(count))
	{
		D3D11_BUFFER_DESC bd {0};
		bd.ByteWidth	= sizeof(uint32_t) * IndexCount;
		bd.Usage		= D3D11_USAGE_DEFAULT;
		bd.BindFlags	= D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA srd {0};
		srd.pSysMem = indices;

		auto res = RHI::Device->CreateBuffer(&bd, &srd, &Buffer);
		AssertCritical(SUCCEEDED(res), "Could not create index buffer.");
	}

	void IndexBuffer::Bind() const
	{
		RHI::Context->IASetIndexBuffer(Buffer.Get(), DXGI_FORMAT_R32_UINT, 0);
	}

	uint32_t IndexBuffer::Count() const
	{
		return IndexCount;
	}
}
