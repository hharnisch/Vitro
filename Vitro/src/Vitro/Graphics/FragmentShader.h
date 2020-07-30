#pragma once

#include "Vitro/Graphics/Shader.h"

namespace Vitro
{
	class FragmentShader : public Shader
	{
	public:
		static FragmentShader* New(const std::string& filePath);
	};
}
