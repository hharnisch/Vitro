#pragma once

#include "Vitro/API/Base/UniformBuffer.h"
#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/Assert.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	template<typename U> class UniformBuffer : public Base::UniformBuffer<U>
	{
	public:
		UniformBuffer(const U& uniformStruct, uint32_t uniformCount) : Count(uniformCount)
		{
			D3D11_BUFFER_DESC bd{0};
			bd.ByteWidth	= sizeof(U);
			bd.Usage		= D3D11_USAGE_DEFAULT;
			bd.BindFlags	= D3D11_BIND_CONSTANT_BUFFER;

			D3D11_SUBRESOURCE_DATA srd{0};
			srd.pSysMem = &uniformStruct;

			auto result = API::Device->CreateBuffer(&bd, &srd, &BufferPtr);
			AssertCritical(SUCCEEDED(result), "Could not create uniform buffer.");
		}

		void Bind() const override
		{
			UINT firstUniform = 0;
			API::Context->VSSetConstantBuffers1(0, 1, BufferPtr.Get(), &firstUniform, &Count);
		}

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> BufferPtr;
		uint32_t Count;
	};
}
