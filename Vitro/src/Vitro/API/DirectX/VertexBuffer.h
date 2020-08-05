#pragma once

#include "Vitro/API/Base/VertexBuffer.h"
#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/HeapArray.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	template<typename V> class VertexBuffer : public Base::VertexBuffer<V>
	{
	public:
		VertexBuffer(const HeapArray<V>& vertices) :
			VertexBuffer(vertices.Raw(), static_cast<uint32_t>(vertices.Count()))
		{}

		VertexBuffer(const V vertices[], uint32_t count) : VertexCount(count)
		{
			D3D11_BUFFER_DESC bd{0};
			bd.ByteWidth	= count * sizeof(V);
			bd.Usage		= D3D11_USAGE_DEFAULT;
			bd.BindFlags	= D3D11_BIND_VERTEX_BUFFER;

			D3D11_SUBRESOURCE_DATA srd{0};
			srd.pSysMem = vertices;

			auto result = API::Device->CreateBuffer(&bd, &srd, &BufferPtr);
			AssertCritical(SUCCEEDED(result), "Could not create vertex buffer.");
		}

		void Bind(VertexTopology vt) const override
		{
			UINT stride = sizeof(V);
			UINT offset = 0;
			API::Context->IASetVertexBuffers(0, 1, BufferPtr.GetAddressOf(), &stride, &offset);
			API::Context->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(vt));
		}

		uint32_t Count() const override
		{
			return VertexCount;
		}

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> BufferPtr;
		uint32_t VertexCount;
	};
}
