#pragma once

#include "Vitro/Graphics/Context3D.h"
#include "Vitro/Graphics/IndexBuffer.h"

#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class Context3D final : public Vitro::Context3D
	{
	public:
		Context3D(void* nativeWindowHandle, uint32_t width, uint32_t height);

		void SetViewport(int width, int height, int x, int y) override;
		void SetClearColor(const Float4& color) override;
		void SetVSync(bool enabled) override;
		void TargetBackBuffer() override;
		void DrawIndices(const Ref<IndexBuffer>& ib) override;
		void SwapBuffers() override;

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain1> SwapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> BackBuffer;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> DepthStencilBuffer;
		uint32_t SwapInterval = 1;
	};
}
