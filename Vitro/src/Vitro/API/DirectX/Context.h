#pragma once

#include "Vitro/Graphics/Context.h"

#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class Context : public Vitro::Context
	{
	public:
		Context(Window* window);
		void SwapBuffers() override;

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain1> SwapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> RenderTarget;
	};
}
