#pragma once

#include "Vitro/Graphics/Shader.h"
#include "Vitro/Utility/Ref.h"

namespace Vitro
{
	class FragmentShader : public Shader
	{
	public:
		static Ref<FragmentShader> New(const std::string& filePath);
	};
}
