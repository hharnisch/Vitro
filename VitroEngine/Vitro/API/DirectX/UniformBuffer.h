#pragma once

#include "Vitro/API/Base/UniformBuffer.h"
#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Utility/Assert.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	template<typename U> class UniformBuffer final : public Base::UniformBuffer<U>
	{
	public:
		UniformBuffer(const U& uniformData, uint32_t uniformCount) : Count(uniformCount)
		{
			D3D11_BUFFER_DESC bd {0};
			bd.ByteWidth	= sizeof(U);
			bd.Usage		= D3D11_USAGE_DEFAULT;
			bd.BindFlags	= D3D11_BIND_CONSTANT_BUFFER;

			D3D11_SUBRESOURCE_DATA srd {0};
			srd.pSysMem = &uniformData;

			auto res = RHI::Get().Device->CreateBuffer(&bd, &srd, &Buffer);
			AssertCritical(SUCCEEDED(res), "Could not create uniform buffer.");
		}

		void Bind() const override
		{
			RHI::Get().Context->VSSetConstantBuffers(0, 1, Buffer.GetAddressOf());
		}

		void Update(const U& uniformData) const override
		{
			RHI::Get().Context->UpdateSubresource(Buffer.Get(), 0, nullptr, &uniformData, 0, 0);
		}

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> Buffer;
		uint32_t Count;
	};
}
