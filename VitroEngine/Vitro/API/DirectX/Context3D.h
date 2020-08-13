#pragma once

#include "Vitro/API/Base/Context3D.h"

#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class Context3D : public Base::Context3D
	{
	public:
		Context3D(void* nativeHandle, uint32_t width, uint32_t height);

		void SetViewport(int width, int height, int x, int y) override;
		void SetClearColor(const Float4& color) override;
		void TargetBackBuffer() override;
		void DrawIndices(const IndexBuffer& ib) override;
		void SwapBuffers() override;

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain1> SwapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> BackBuffer;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> DepthBuffer;
	};
}
