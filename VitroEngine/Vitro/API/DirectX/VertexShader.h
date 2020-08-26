#pragma once

#include "Vitro/API/DirectX/Scope.h"
#include "Vitro/Graphics/Shader.h"

#include <d3d11_4.h>

namespace Vitro::DirectX
{
	class VertexShader final : public Vitro::VertexShader
	{
	public:
		VertexShader(const std::string& filePath);

		void Bind() const override;
		void SetVertexLayout(const VertexLayout& vl) override;

	private:
		Scope<ID3D11VertexShader> ShaderPtr;
	};
}
