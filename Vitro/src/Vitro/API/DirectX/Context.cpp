#include "_pch.h"
#include "Context.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Utility/Assert.h"

#include <dxgi1_2.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	Context::Context(Window* window)
	{
		using namespace Microsoft::WRL;
		ComPtr<IDXGIDevice1> dxgiDevice;
		API::Device.As(&dxgiDevice);
		ComPtr<IDXGIAdapter> adapter;
		dxgiDevice->GetAdapter(&adapter);
		ComPtr<IDXGIFactory2> factory;
		adapter->GetParent(__uuidof(IDXGIFactory2), &factory);

		DXGI_SWAP_CHAIN_DESC1 scd{0};
		scd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		scd.SampleDesc.Count = 1;
		scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.BufferCount = 2;
		scd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsd{0};
		fsd.Windowed = true;

		HWND hwnd = dynamic_cast<Windows::Window*>(window)->GetNativeHandle();
		auto result = factory->CreateSwapChainForHwnd(API::Device.Get(), hwnd, &scd, &fsd, nullptr,
													  &SwapChain);
		Assert(SUCCEEDED(result), "Unable to create swap chain.");

		ComPtr<ID3D11Texture2D> backBuffer;
		SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backBuffer);

		API::Device->CreateRenderTargetView(backBuffer.Get(), nullptr, &RenderTarget);
	}

	void Context::SwapBuffers()
	{
		API::DeviceContext->OMSetRenderTargets(1, RenderTarget.GetAddressOf(), nullptr);
		SwapChain->Present(1, 0);
	}
}
