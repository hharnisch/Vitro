#pragma once

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class RHI final
	{
	public:
		static void Initialize();

		static inline Microsoft::WRL::ComPtr<ID3D11Device5> Device;
		static inline Microsoft::WRL::ComPtr<ID3D11DeviceContext4> Context;

	#if VTR_DEBUG
		static inline Microsoft::WRL::ComPtr<ID3D11Debug> DebugLayer;
	#endif

		RHI() = delete;
	};
}
