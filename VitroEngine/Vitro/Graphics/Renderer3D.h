#pragma once

#include "Vitro/API/Base/Window.h"
#include "Vitro/Graphics/Context3D.h"
#include "Vitro/Graphics/VertexBuffer.h"

namespace Vitro
{
	class Renderer3D
	{
	public:
		Renderer3D(const Base::Window& window);

		void BeginScene();
		void EndScene();
		void Submit(const IndexBuffer& ib);

	private:
		std::unique_ptr<Context3D> Context;
	};
}
