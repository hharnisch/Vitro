#include "_pch.h"
#include "API.h"

#include "Vitro/Utility/Assert.h"

namespace Vitro::DirectX
{
	Microsoft::WRL::ComPtr<ID3D11Device5> API::Device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext4> API::Context;
#if VTR_DEBUG
	Microsoft::WRL::ComPtr<ID3D11Debug> API::DebugLayer;
#endif

	void API::Initialize()
	{
		static bool initialized;
		AssertCritical(!initialized, "DirectX API already initialized.");

		UINT flags = 0;
	#if VTR_DEBUG
		flags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif
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
		ComPtr<ID3D11DeviceContext> context;
		auto result = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags,
										featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION,
										&device, nullptr, &context);
		AssertCritical(SUCCEEDED(result), "DirectX device could not be created.");
		device.As(&API::Device);
		context.As(&API::Context);

	#if VTR_DEBUG
		auto query = API::Device->QueryInterface(__uuidof(ID3D11Debug), &DebugLayer);
		AssertCritical(SUCCEEDED(query), "Could not get debug layer.");
	#endif

		initialized = true;
	}
}
