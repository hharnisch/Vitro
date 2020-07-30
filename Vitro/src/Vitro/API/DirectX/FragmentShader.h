#pragma once

#include "Vitro/Graphics/FragmentShader.h"

#include <d3d11_4.h>
#include <wrl.h>

namespace Vitro::DirectX
{
	class FragmentShader : public Vitro::FragmentShader
	{
	public:
		FragmentShader(const std::string& filePath);

		void Bind() override;
		void Unbind() override;
		void SetInt(const std::string& name, int value) override;
		void SetIntArray(const std::string& name, const Array<int>& arr) override;
		void SetFloat(const std::string& name, float value) override;
		void SetFloat3(const std::string& name, const Vec3& value) override;
		void SetFloat4(const std::string& name, const Vec4& value) override;
		void SetMat4(const std::string& name, const Mat4& value) override;

	private:
		Microsoft::WRL::ComPtr<ID3D11PixelShader> ShaderPtr;
	};
}
