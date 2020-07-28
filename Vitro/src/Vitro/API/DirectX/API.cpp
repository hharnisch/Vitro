#include "_pch.h"
#include "API.h"

#include "Vitro/Utility/Assert.h"

namespace Vitro::DirectX
{
	Microsoft::WRL::ComPtr<ID3D11Device1> API::Device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1> API::DeviceContext;

	void API::Initialize()
	{
		static bool Initialized;
		Assert(!Initialized, "DirectX API already initialized.");

		using namespace Microsoft::WRL;
		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> deviceContext;
		auto result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
										D3D11_SDK_VERSION, &device, nullptr, &deviceContext);
		Assert(SUCCEEDED(result), "DirectX device could not be created.");

		device.As(&API::Device);
		deviceContext.As(&API::DeviceContext);

		Initialized = true;
	}
}
