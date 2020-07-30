#include "_pch.h"
#include "FragmentShader.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/FileUtils.h"

namespace Vitro::DirectX
{
	FragmentShader::FragmentShader(const std::string& filePath)
	{
		auto data = FileUtils::GetBinaryData(filePath);
		API::Device->CreatePixelShader(data.Data, data.Count(), nullptr, &ShaderPtr);
	}

	void FragmentShader::Bind()
	{
		API::DeviceContext->PSSetShader(ShaderPtr.Get(), nullptr, 0);
	}

	void FragmentShader::Unbind()
	{}

	void FragmentShader::SetInt(const std::string& name, int value)
	{}

	void FragmentShader::SetIntArray(const std::string& name, const Array<int>& arr)
	{}

	void FragmentShader::SetFloat(const std::string& name, float value)
	{}

	void FragmentShader::SetFloat3(const std::string& name, const Vec3& value)
	{}

	void FragmentShader::SetFloat4(const std::string& name, const Vec4& value)
	{}

	void FragmentShader::SetMat4(const std::string& name, const Mat4& value)
	{}
}
