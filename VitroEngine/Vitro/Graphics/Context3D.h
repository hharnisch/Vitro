#pragma once

#include "Vitro/Graphics/IndexBuffer.h"
#include "Vitro/Math/Vector.h"
#include "Vitro/Utility/Ref.h"
#include "Vitro/Utility/Scope.h"

namespace Vitro
{
	class Context3D
	{
	public:
		static Scope<Context3D> New(void* nativeWindowHandle, uint32_t width, uint32_t height);

		virtual ~Context3D() = default;

		virtual void SetViewport(int width, int height, int x, int y) = 0;
		virtual void SetClearColor(const Float4& color) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual void TargetBackBuffer() = 0;
		virtual void DrawIndices(const Ref<IndexBuffer>& ib) = 0;
		virtual void SwapBuffers() = 0;
	};
}
