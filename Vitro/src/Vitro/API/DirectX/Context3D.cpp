#include "_pch.h"
#include "Context3D.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/Assert.h"

#include <dxgi1_6.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	Context3D::Context3D(void* nativeHandle)
	{
		using namespace Microsoft::WRL;
		ComPtr<IDXGIDevice1> dxgiDevice;
		API::Device.As(&dxgiDevice);
		ComPtr<IDXGIAdapter> adapter;
		dxgiDevice->GetAdapter(&adapter);
		ComPtr<IDXGIFactory2> factory;
		adapter->GetParent(__uuidof(IDXGIFactory2), &factory);

		DXGI_SWAP_CHAIN_DESC1 scd{0};
		scd.Format				= DXGI_FORMAT_R8G8B8A8_UNORM;
		scd.SampleDesc.Count	= 1;
		scd.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.BufferCount			= 2;
		scd.SwapEffect			= DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsd{0};
		fsd.Windowed = true;

		HWND hwnd = reinterpret_cast<HWND>(nativeHandle);
		auto swapChainResult = factory->CreateSwapChainForHwnd(API::Device.Get(), hwnd, &scd, &fsd,
															   nullptr, &SwapChain);
		AssertCritical(SUCCEEDED(swapChainResult), "Could not create swap chain.");

		ComPtr<ID3D11Texture2D> backBuffer;
		auto bufferResult = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backBuffer);
		AssertCritical(SUCCEEDED(bufferResult), "Could not get back buffer.");

		auto rtResult = API::Device->CreateRenderTargetView(backBuffer.Get(), nullptr, &BackBuffer);
		AssertCritical(SUCCEEDED(rtResult), "Could not create render target on back buffer.");
	}

	void Context3D::SetViewport(int width, int height, int x, int y)
	{
		D3D11_VIEWPORT viewport{0};
		viewport.TopLeftX	= static_cast<FLOAT>(x);
		viewport.TopLeftY	= static_cast<FLOAT>(y);
		viewport.Width		= static_cast<FLOAT>(width);
		viewport.Height		= static_cast<FLOAT>(height);
		API::Context->RSSetViewports(1, &viewport);
	}

	void Context3D::SetClearColor(const Float4& color)
	{
		API::Context->ClearRenderTargetView(BackBuffer.Get(), color.Val);
	}

	void Context3D::TargetBackBuffer()
	{
		API::Context->OMSetRenderTargets(1, BackBuffer.GetAddressOf(), nullptr);
	}

	void Context3D::DrawIndices(const IndexBuffer& ib)
	{
		API::Context->DrawIndexed(ib.Count(), 0, 0);
	}

	void Context3D::SwapBuffers()
	{
		auto result = SwapChain->Present(1, 0);
		Assert(SUCCEEDED(result), "Swap chain could not present image.");
	}
}
