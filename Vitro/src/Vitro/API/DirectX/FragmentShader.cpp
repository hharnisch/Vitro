#include "_pch.h"
#include "FragmentShader.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/FileUtils.h"

namespace Vitro::DirectX
{
	FragmentShader::FragmentShader(const std::string& filePath)
	{
		Bytecode = FileUtils::GetBinaryData(filePath);
		auto result = API::Device->CreatePixelShader(Bytecode.Raw(), Bytecode.Count(), nullptr,
													 &ShaderPtr);
		AssertCritical(SUCCEEDED(result), "Could not create fragment shader.");
	}

	void FragmentShader::Bind()
	{
		API::Context->PSSetShader(ShaderPtr.Get(), nullptr, 0);
	}
}
