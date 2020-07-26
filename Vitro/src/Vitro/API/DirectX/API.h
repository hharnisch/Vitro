#pragma once

#include <d3d11.h>

namespace Vitro::DirectX
{
	class API
	{
	public:
		static void Initialize();
		static void Finalize();

		static ID3D11Device* Device;
		static ID3D11DeviceContext* DeviceContext;

	private:
		API() = delete;
	};
}
