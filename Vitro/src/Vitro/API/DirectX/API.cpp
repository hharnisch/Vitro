#include "_pch.h"
#include "API.h"

#include "Vitro/Diagnostics/Assert.h"

namespace Vitro::DirectX
{
	ID3D11Device* API::Device;
	ID3D11DeviceContext* API::DeviceContext;

	void API::Initialize()
	{
		D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
						  D3D11_SDK_VERSION, &API::Device, nullptr, &API::DeviceContext);
	}

	void API::Finalize()
	{
		Device->Release();
		DeviceContext->Release();
	}
}
