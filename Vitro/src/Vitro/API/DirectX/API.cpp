#include "_pch.h"
#include "API.h"

#include "Vitro/Utility/Assert.h"

namespace Vitro::DirectX
{
	Microsoft::WRL::ComPtr<ID3D11Device5> API::Device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext4> API::DeviceContext;

	void API::Initialize()
	{
		static bool Initialized;
		Assert(!Initialized, "DirectX API already initialized.");

		D3D_FEATURE_LEVEL featureLevels[]
		{
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
			D3D_FEATURE_LEVEL_9_3,
			D3D_FEATURE_LEVEL_9_2,
			D3D_FEATURE_LEVEL_9_1,
		};

		using namespace Microsoft::WRL;
		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> deviceContext;
		auto result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
										featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION,
										&device, nullptr, &deviceContext);
		Assert(SUCCEEDED(result), "DirectX device could not be created.");

		device.As(&API::Device);
		deviceContext.As(&API::DeviceContext);

		Initialized = true;
	}
}
