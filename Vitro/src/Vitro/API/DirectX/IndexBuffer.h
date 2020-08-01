#pragma once

#include "Vitro/API/Base/IndexBuffer.h"
#include "Vitro/Utility/Array.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class IndexBuffer : public Base::IndexBuffer
	{
	public:
		IndexBuffer(const Array<uint32_t>& indices);
		IndexBuffer(const uint32_t indices[], size_t count);

		void Bind() const override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> BufferPtr;
	};
}
