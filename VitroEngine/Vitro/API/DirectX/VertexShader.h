#pragma once

#include "Vitro/Graphics/VertexShader.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class VertexShader final : public Vitro::VertexShader
	{
	public:
		VertexShader(const std::string& filePath);

		void Bind() override;
		void SetVertexLayout(const VertexLayout& vl) override;

	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> ShaderPtr;
	};
}
