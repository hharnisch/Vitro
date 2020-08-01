#include "_pch.h"
#include "IndexBuffer.h"

#include "Vitro/API/DirectX/API.h"

namespace Vitro::DirectX
{
	IndexBuffer::IndexBuffer(const Array<uint32_t>& indices) :
		IndexBuffer(indices.Raw(), indices.Count())
	{}

	IndexBuffer::IndexBuffer(const uint32_t indices[], size_t count)
	{
		D3D11_BUFFER_DESC bd{0};
		bd.ByteWidth = static_cast<UINT>(count * sizeof(uint32_t));
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA srd{0};
		srd.pSysMem = indices;

		API::Device->CreateBuffer(&bd, &srd, &BufferPtr);
	}

	void IndexBuffer::Bind() const
	{
		API::Context->IASetIndexBuffer(BufferPtr.Get(), DXGI_FORMAT_R32_UINT, 0);
	}
}
