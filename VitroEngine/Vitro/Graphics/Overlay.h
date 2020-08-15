#pragma once

#include "Vitro/Graphics/Layer.h"

namespace Vitro
{
	class Overlay : public Layer
	{
	public:
		Overlay() = default;

		Overlay(const Overlay&) = delete;
		Overlay(Overlay&&) = delete;
		Overlay& operator=(const Overlay&) = delete;
		Overlay& operator=(Overlay&&) = delete;
	};
}
