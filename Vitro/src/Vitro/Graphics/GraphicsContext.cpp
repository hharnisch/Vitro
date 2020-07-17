#include "_pch.h"
#include "GraphicsContext.h"

#include "Vitro/API/OpenGL/Context.h"

namespace Vitro
{
	GraphicsContext* GraphicsContext::New(Window* window)
	{
	#if $OPENGL
		return new OpenGL::Context(window);
	#endif
	}
}
