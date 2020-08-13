#pragma once

#include "Vitro/API/Base/FragmentShader.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class FragmentShader : public Base::FragmentShader
	{
	public:
		FragmentShader(const std::string& filePath);

		void Bind() override;

	private:
		Microsoft::WRL::ComPtr<ID3D11PixelShader> ShaderPtr;
	};
}
