#include "_pch.h"
#include "API.h"

#include "Vitro/Diagnostics/Assert.h"

namespace Vitro::DirectX
{
	WRL::ComPtr<ID3D11Device1> API::Device;
	WRL::ComPtr<ID3D11DeviceContext1> API::DeviceContext;

	void API::Initialize()
	{
		static bool Initialized;
		Assert(!Initialized, "DirectX API already initialized.");

		WRL::ComPtr<ID3D11Device> device;
		WRL::ComPtr<ID3D11DeviceContext> deviceContext;
		auto result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
										D3D11_SDK_VERSION, &device, nullptr, &deviceContext);
		Assert(SUCCEEDED(result), "DirectX device could not be created.");

		device.As(&API::Device);
		deviceContext.As(&API::DeviceContext);

		Initialized = true;
	}
}
