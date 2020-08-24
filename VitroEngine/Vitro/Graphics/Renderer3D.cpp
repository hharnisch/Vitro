#include "_pch.h"
#include "Renderer3D.h"

#include "Vitro/Application/Window.h"

namespace Vitro
{
	Renderer3D::Renderer3D(void* nativeWindowHandle, int width, int height)
	{
		Context = Context3D::New(nativeWindowHandle, width, height);
		Context->SetViewport(width, height, 0, 0);
	}

	void Renderer3D::BeginScene()
	{
		Context->SetClearColor({1, 0, 1, 1});
		Context->TargetBackBuffer();
	}

	void Renderer3D::EndScene()
	{
		Context->SwapBuffers();
	}

	void Renderer3D::Submit(const Ref<IndexBuffer>& ib)
	{
		ib->Bind();
		Context->DrawIndices(ib);
	}
}
