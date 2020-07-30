#pragma once

#include "Vitro/Graphics/Shader.h"

namespace Vitro
{
	class VertexShader : public Shader
	{
	public:
		static VertexShader* New(const std::string& filePath);
	};
}
