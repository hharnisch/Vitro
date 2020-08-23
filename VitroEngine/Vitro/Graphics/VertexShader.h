#pragma once

#include "Vitro/Graphics/Shader.h"
#include "Vitro/Graphics/VertexLayout.h"

namespace Vitro
{
	class VertexShader : public Shader
	{
	public:
		static Ref<VertexShader> New(const std::string& filePath);

		virtual void SetVertexLayout(const VertexLayout& vl) = 0;
	};
}
