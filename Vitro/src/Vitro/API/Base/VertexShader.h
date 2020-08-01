#pragma once

#include "Vitro/API/Base/Shader.h"
#include "Vitro/Graphics/VertexField.h"

namespace Vitro::Base
{
	class VertexShader : public Shader
	{
	public:
		virtual void SetVertexLayout(Vitro::VertexField fields[], uint32_t count) = 0;
	};
}
