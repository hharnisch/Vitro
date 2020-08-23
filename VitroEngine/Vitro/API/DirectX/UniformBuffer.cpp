#include "_pch.h"
#include "UniformBuffer.h"

namespace Vitro::DirectX
{
	UniformBuffer::UniformBuffer(const void* uniforms, size_t size)
	{
		D3D11_BUFFER_DESC bd {0};
		bd.ByteWidth	= static_cast<UINT>(size);
		bd.Usage		= D3D11_USAGE_DEFAULT;
		bd.BindFlags	= D3D11_BIND_CONSTANT_BUFFER;

		D3D11_SUBRESOURCE_DATA srd {0};
		srd.pSysMem = uniforms;

		auto res = RHI::Device->CreateBuffer(&bd, &srd, &Buffer);
		AssertCritical(SUCCEEDED(res), "Could not create uniform buffer.");
	}

	void UniformBuffer::Bind() const
	{
		RHI::Context->VSSetConstantBuffers(0, 1, Buffer.GetAddressOf());
	}

	void UniformBuffer::Update(const void* uniforms) const
	{
		RHI::Context->UpdateSubresource(Buffer.Get(), 0, nullptr, uniforms, 0, 0);
	}
}
