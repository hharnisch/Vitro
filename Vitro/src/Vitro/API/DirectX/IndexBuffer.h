#pragma once

#include "Vitro/API/Base/IndexBuffer.h"
#include "Vitro/Utility/HeapArray.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class IndexBuffer : public Base::IndexBuffer
	{
	public:
		IndexBuffer(const HeapArray<uint32_t>& indices);
		IndexBuffer(const uint32_t indices[], uint32_t count);

		void Bind() const override;
		uint32_t Count() const override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> BufferPtr;
		uint32_t IndexCount;
	};
}
