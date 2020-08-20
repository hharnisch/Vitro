#include "_pch.h"
#include "RHI.h"

#include "Vitro/Utility/Assert.h"

namespace Vitro::DirectX
{
	RHI::RHI()
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
		auto res = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags,
									 featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION,
									 &device, nullptr, &context);
		AssertCritical(SUCCEEDED(res), "DirectX device could not be created.");
		device.As(&Device);
		context.As(&Context);

	#if VTR_DEBUG
		auto query = Device->QueryInterface(__uuidof(ID3D11Debug), &DebugLayer);
		AssertCritical(SUCCEEDED(query), "Could not get debug layer.");
	#endif

		initialized = true;
	}
}
