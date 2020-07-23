#pragma once

#include "Vitro/Graphics/GraphicsContext.h"
#include "Vitro/Graphics/Window.h"

namespace Vitro::OpenGL
{
	class Context : public GraphicsContext
	{
	public:
		Context(Window* window);

		void Initialize() override;
		void SwapBuffers() override;

	private:
		Window* WindowHandle;
	};
}
