#include "_pch.h"
#include "IndexBuffer.h"

#include "Vitro/API/DirectX/API.h"

namespace Vitro::DirectX
{
	IndexBuffer::IndexBuffer(const HeapArray<uint32_t>& indices) :
		IndexBuffer(indices.Raw(), static_cast<uint32_t>(indices.Count()))
	{}

	IndexBuffer::IndexBuffer(const uint32_t indices[], uint32_t count) : IndexCount(count)
	{
		D3D11_BUFFER_DESC bd{0};
		bd.ByteWidth	= count * sizeof(uint32_t);
		bd.Usage		= D3D11_USAGE_DEFAULT;
		bd.BindFlags	= D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA srd{0};
		srd.pSysMem = indices;

		auto result = API::Device->CreateBuffer(&bd, &srd, &BufferPtr);
		AssertCritical(SUCCEEDED(result), "Could not create index buffer.");
	}

	void IndexBuffer::Bind() const
	{
		API::Context->IASetIndexBuffer(BufferPtr.Get(), DXGI_FORMAT_R32_UINT, 0);
	}

	uint32_t IndexBuffer::Count() const
	{
		return IndexCount;
	}
}
