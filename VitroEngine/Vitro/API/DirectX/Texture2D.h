#pragma once

#include "Vitro/Graphics/Texture.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class Texture2D final : public Vitro::Texture2D
	{
	public:
		Texture2D(const std::string& filePath);

		void Bind() const override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Texture2D> Texture;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> Resource;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> Sampler;
	};
}
