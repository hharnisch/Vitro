#pragma once

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class API
	{
	public:
		static void Initialize();

		static Microsoft::WRL::ComPtr<ID3D11Device5> Device;
		static Microsoft::WRL::ComPtr<ID3D11DeviceContext4> Context;
	#if VTR_DEBUG
		static Microsoft::WRL::ComPtr<ID3D11Debug> DebugLayer;
	#endif

	private:
		API() = delete;
	};
}
