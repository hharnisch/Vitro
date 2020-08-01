#pragma once

#include "Vitro/API/Base/Context3D.h"
#include "Vitro/Graphics/Window.h"

#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class Context3D : public Base::Context3D
	{
	public:
		Context3D(Window* window);

		void SetViewport(int width, int height, int x, int y) override;
		void TargetBackBuffer() override;
		void SwapBuffers() override;

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain1> SwapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> BackBuffer;
	};
}
