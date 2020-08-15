#pragma once

#include "Vitro/Graphics/IndexBuffer.h"
#include "Vitro/Math/Vector.h"

namespace Vitro::Base
{
	class Context3D
	{
	public:
		virtual void SetViewport(int width, int height, int x, int y) = 0;
		virtual void SetClearColor(const Float4& color) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual void TargetBackBuffer() = 0;
		virtual void DrawIndices(const Vitro::IndexBuffer& ib) = 0;
		virtual void SwapBuffers() = 0;
	};
}
