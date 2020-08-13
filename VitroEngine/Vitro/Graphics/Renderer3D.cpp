#include "_pch.h"
#include "Renderer3D.h"

#include "Vitro/Graphics/Window.h"

namespace Vitro
{
	Renderer3D::Renderer3D(const Base::Window& window)
	{
		Context = std::make_unique<Context3D>(window.GetNativeHandle(), window.GetViewportWidth(),
											  window.GetViewportHeight());
		Context->SetViewport(window.GetWidth(), window.GetHeight(), 0, 0);
	}

	void Renderer3D::BeginScene()
	{
		Context->SetClearColor({0, 0, 0, 1});
		Context->TargetBackBuffer();
	}

	void Renderer3D::EndScene()
	{
		Context->SwapBuffers();
	}

	void Renderer3D::Submit(const IndexBuffer& ib)
	{
		ib.Bind();
		Context->DrawIndices(ib);
	}
}
