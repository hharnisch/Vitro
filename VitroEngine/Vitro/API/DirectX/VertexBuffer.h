#pragma once

#include "Vitro/API/Base/VertexBuffer.h"
#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Utility/HeapArray.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	template<typename V> class VertexBuffer final : public Base::VertexBuffer<V>
	{
	public:
		VertexBuffer(const HeapArray<V>& vertices) : VertexBuffer(vertices.Raw(), vertices.Count())
		{}

		VertexBuffer(const V vertices[], size_t count) : VertexCount(count)
		{
			D3D11_BUFFER_DESC bd {0};
			bd.ByteWidth	= sizeof(V) * static_cast<uint32_t>(count);
			bd.Usage		= D3D11_USAGE_DEFAULT;
			bd.BindFlags	= D3D11_BIND_VERTEX_BUFFER;

			D3D11_SUBRESOURCE_DATA srd {0};
			srd.pSysMem = vertices;

			auto res = RHI::Get().Device->CreateBuffer(&bd, &srd, &Buffer);
			AssertCritical(SUCCEEDED(res), "Could not create vertex buffer.");
		}

		void Bind(VertexTopology vt) const override
		{
			UINT stride = sizeof(V);
			UINT offset = 0;
			RHI::Get().Context->IASetVertexBuffers(0, 1, Buffer.GetAddressOf(), &stride, &offset);
			RHI::Get().Context->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(vt));
		}

		size_t Count() const override
		{
			return VertexCount;
		}

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> Buffer;
		size_t VertexCount;
	};
}
