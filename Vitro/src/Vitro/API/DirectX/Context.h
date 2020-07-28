#pragma once

#include "Vitro/Graphics/Context.h"

#include <dxgi1_2.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class Context : public Vitro::Context
	{
	public:
		Context(Window* window);

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain1> SwapChain;
	};
}
