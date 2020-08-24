#include "_pch.h"
#include "Context3D.h"

#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Utility/Assert.h"

#include <dxgi1_6.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	Context3D::Context3D(void* nativeWindowHandle, uint32_t width, uint32_t height)
	{
		using namespace Microsoft::WRL;
		ComPtr<IDXGIDevice1> dxgiDevice;
		RHI::Device.As(&dxgiDevice);
		ComPtr<IDXGIAdapter> adapter;
		dxgiDevice->GetAdapter(&adapter);
		ComPtr<IDXGIFactory2> factory;
		adapter->GetParent(__uuidof(IDXGIFactory2), &factory);

		DXGI_SWAP_CHAIN_DESC1 scd;
		scd.Width				= 0;
		scd.Height				= 0;
		scd.Format				= DXGI_FORMAT_R8G8B8A8_UNORM;
		scd.Stereo				= false;
		scd.SampleDesc.Count	= 1;
		scd.SampleDesc.Quality	= 0;
		scd.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.BufferCount			= 2;
		scd.Scaling				= DXGI_SCALING_STRETCH;
		scd.SwapEffect			= DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
		scd.AlphaMode			= DXGI_ALPHA_MODE_UNSPECIFIED;
		scd.Flags				= 0;

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsd;
		fsd.RefreshRate.Numerator	= 0;
		fsd.RefreshRate.Denominator	= 0;
		fsd.ScanlineOrdering		= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		fsd.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;
		fsd.Windowed				= true;

		HWND hwnd = reinterpret_cast<HWND>(nativeWindowHandle);
		auto scRes = factory->CreateSwapChainForHwnd(RHI::Device.Get(), hwnd, &scd, &fsd, nullptr,
													 &SwapChain);
		AssertCritical(SUCCEEDED(scRes), "Could not create swap chain.");

		ComPtr<ID3D11Texture2D> rtTexture;
		auto rtTexRes = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &rtTexture);
		AssertCritical(SUCCEEDED(rtTexRes), "Could not get render target texture.");

		auto rtRes = RHI::Device->CreateRenderTargetView(rtTexture.Get(), nullptr, &BackBuffer);
		AssertCritical(SUCCEEDED(rtRes), "Could not create back buffer.");

		D3D11_TEXTURE2D_DESC t2dd;
		t2dd.Width				= width;
		t2dd.Height				= height;
		t2dd.MipLevels			= 1;
		t2dd.ArraySize			= 1;
		t2dd.Format				= DXGI_FORMAT_D24_UNORM_S8_UINT;
		t2dd.SampleDesc.Count	= 1;
		t2dd.SampleDesc.Quality	= 0;
		t2dd.Usage				= D3D11_USAGE_DEFAULT;
		t2dd.BindFlags			= D3D11_BIND_DEPTH_STENCIL;
		t2dd.CPUAccessFlags		= 0;
		t2dd.MiscFlags			= 0;

		ComPtr<ID3D11Texture2D> dsTexture;
		auto dsTexRes = RHI::Device->CreateTexture2D(&t2dd, nullptr, &dsTexture);
		AssertCritical(SUCCEEDED(dsTexRes), "Could not create depth stencil texture.");

		auto dsRes = RHI::Device->CreateDepthStencilView(dsTexture.Get(), nullptr,
														 &DepthStencilBuffer);
		AssertCritical(SUCCEEDED(dsRes), "Could not create depth stencil buffer.");
	}

	void Context3D::SetViewport(int width, int height, int x, int y)
	{
		D3D11_VIEWPORT viewport;
		viewport.TopLeftX	= static_cast<FLOAT>(x);
		viewport.TopLeftY	= static_cast<FLOAT>(y);
		viewport.Width		= static_cast<FLOAT>(width);
		viewport.Height		= static_cast<FLOAT>(height);
		viewport.MinDepth	= 0.0;
		viewport.MaxDepth	= 1.0;
		RHI::Context->RSSetViewports(1, &viewport);
	}

	void Context3D::SetClearColor(const Float4& color)
	{
		RHI::Context->ClearRenderTargetView(BackBuffer.Get(), color.Raw);
		RHI::Context->ClearDepthStencilView(DepthStencilBuffer.Get(),
											D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	}

	void Context3D::SetVSync(bool enabled)
	{
		SwapInterval = enabled ? 1 : 0;
	}

	void Context3D::TargetBackBuffer()
	{
		RHI::Context->OMSetRenderTargets(1, BackBuffer.GetAddressOf(), DepthStencilBuffer.Get());
	}

	void Context3D::DrawIndices(const Ref<IndexBuffer>& ib)
	{
		RHI::Context->DrawIndexed(ib->Count(), 0, 0);
	}

	void Context3D::SwapBuffers()
	{
		auto res = SwapChain->Present(SwapInterval, 0);
		AssertDebug(SUCCEEDED(res), "Swap chain could not present image.");
	}
}
