#pragma once

#include "Vitro/API/Base/VertexBuffer.h"
#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/Array.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	template<typename V> class VertexBuffer : public Base::VertexBuffer<V>
	{
	public:
		VertexBuffer(const Array<V>& vertices) :
			VertexBuffer(vertices.Raw(), static_cast<uint32_t>(vertices.Count()))
		{}

		VertexBuffer(const V vertices[], uint32_t count) : Count(count)
		{
			D3D11_BUFFER_DESC bd{0};
			bd.ByteWidth = Count * sizeof(V);
			bd.Usage = D3D11_USAGE_DEFAULT;
			bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

			D3D11_SUBRESOURCE_DATA srd{0};
			srd.pSysMem = vertices;

			API::Device->CreateBuffer(&bd, &srd, &BufferPtr);
		}

		void Bind(VertexTopology topology) const override
		{
			UINT stride = sizeof(V);
			UINT offset = 0;
			API::Context->IASetVertexBuffers(0, 1, BufferPtr.GetAddressOf(), &stride, &offset);
			API::Context->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(topology));
			API::Context->Draw(Count, 0);
		}

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> BufferPtr;
		uint32_t Count;
	};
}
