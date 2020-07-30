#include "_pch.h"
#include "VertexShader.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/FileUtils.h"

namespace Vitro::DirectX
{
	VertexShader::VertexShader(const std::string& filePath)
	{
		auto data = FileUtils::GetBinaryData(filePath);
		API::Device->CreateVertexShader(data.Data, data.Count(), nullptr, &ShaderPtr);
	}

	void VertexShader::Bind()
	{
		API::DeviceContext->VSSetShader(ShaderPtr.Get(), nullptr, 0);
	}

	void VertexShader::Unbind()
	{}

	void VertexShader::SetInt(const std::string& name, int value)
	{}

	void VertexShader::SetIntArray(const std::string& name, const Array<int>& arr)
	{}

	void VertexShader::SetFloat(const std::string& name, float value)
	{}

	void VertexShader::SetFloat3(const std::string& name, const Vec3& value)
	{}

	void VertexShader::SetFloat4(const std::string& name, const Vec4& value)
	{}

	void VertexShader::SetMat4(const std::string& name, const Mat4& value)
	{}
}
