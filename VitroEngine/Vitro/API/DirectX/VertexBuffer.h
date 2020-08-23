#pragma once

#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Graphics/VertexBuffer.h"
#include "Vitro/Utility/HeapArray.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class VertexBuffer final : public Vitro::VertexBuffer
	{
	public:
		VertexBuffer(const void* vertices, size_t stride, size_t size);

		void Bind(VertexTopology vt) const override;
		void Update(const void* vertices) const override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> Buffer;
		uint32_t Stride;
		uint32_t Size;
	};
}
