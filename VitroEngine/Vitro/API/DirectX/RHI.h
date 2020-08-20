#pragma once

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class RHI final
	{
	public:
		static inline RHI& Get() { static RHI singleton; return singleton; }

		Microsoft::WRL::ComPtr<ID3D11Device5> Device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext4> Context;
		Microsoft::WRL::ComPtr<ID3D11Debug> DebugLayer;

	private:
		RHI();
	};
}
