#pragma once

namespace Vitro::Base
{
	class Context3D
	{
	public:
		virtual void SetViewport(int width, int height, int x, int y) = 0;
		virtual void TargetBackBuffer() = 0;
		virtual void SwapBuffers() = 0;
	};
}
