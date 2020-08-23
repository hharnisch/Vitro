#include "_pch.h"
#include "FragmentShader.h"

#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Utility/FileUtils.h"

namespace Vitro::DirectX
{
	FragmentShader::FragmentShader(const std::string& filePath)
	{
		Bytecode = GetBinaryFileData(filePath);
		auto res = RHI::Device->CreatePixelShader(Bytecode.Raw(), Bytecode.Count(), nullptr,
												  &ShaderPtr);
		AssertCritical(SUCCEEDED(res), "Could not create fragment shader.");
	}

	void FragmentShader::Bind()
	{
		RHI::Context->PSSetShader(ShaderPtr.Get(), nullptr, 0);
	}
}
