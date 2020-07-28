#pragma once

#include <d3d11_1.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class API
	{
	public:
		static void Initialize();

		static Microsoft::WRL::ComPtr<ID3D11Device1> Device;
		static Microsoft::WRL::ComPtr<ID3D11DeviceContext1> DeviceContext;

	private:
		API() = delete;
	};
}
