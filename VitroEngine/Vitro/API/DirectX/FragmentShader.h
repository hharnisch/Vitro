#pragma once

#include "Vitro/Graphics/FragmentShader.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class FragmentShader final : public Vitro::FragmentShader
	{
	public:
		FragmentShader(const std::string& filePath);

		void Bind() const override;

	private:
		Microsoft::WRL::ComPtr<ID3D11PixelShader> ShaderPtr;
	};
}
