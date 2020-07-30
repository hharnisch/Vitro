#include "_pch.h"
#include "Context.h"

#include "Vitro/API/DirectX/Context.h"

namespace Vitro
{
	Context* Context::New(Window* window)
	{
	#if $DIRECTX
		return new DirectX::Context(window);
	#else
	#error Unsupported graphics API.
	#endif
	}
}
