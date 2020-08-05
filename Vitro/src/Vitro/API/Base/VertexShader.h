#pragma once

#include "Vitro/API/Base/Shader.h"
#include "Vitro/Graphics/VertexLayout.h"

namespace Vitro::Base
{
	class VertexShader : public Shader
	{
	public:
		virtual void SetVertexLayout(const VertexLayout& layout) = 0;
	};
}
