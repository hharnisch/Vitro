#pragma once

#include "Vitro/Graphics/Context3D.h"
#include "Vitro/Graphics/VertexBuffer.h"
#include "Vitro/Utility/Ref.h"

namespace Vitro
{
	class Renderer3D final : public RefCounted
	{
	public:
		Renderer3D(void* nativeWindowHandle, int width, int height);
		virtual ~Renderer3D() = default;

		void BeginScene();
		void EndScene();
		void Submit(const Ref<IndexBuffer>& ib);

	private:
		Scope<Context3D> Context;
	};
}
