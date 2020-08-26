#include "_pch.h"
#include "FragmentShader.h"

#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Utility/File.h"

namespace Vitro::DirectX
{
	FragmentShader::FragmentShader(const std::string& filePath)
	{
		Bytecode = File::LoadBinary(filePath);
		auto res = RHI::Device->CreatePixelShader(Bytecode.Raw(), Bytecode.Count(), nullptr,
												  &ShaderPtr);
		AssertCritical(SUCCEEDED(res), "Could not create fragment shader.");
	}

	void FragmentShader::Bind() const
	{
		RHI::Context->PSSetShader(ShaderPtr, nullptr, 0);
	}
}
