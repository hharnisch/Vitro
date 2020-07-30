#include "_pch.h"
#include "FragmentShader.h"

#include "Vitro/API/DirectX/FragmentShader.h"

namespace Vitro
{
	FragmentShader* FragmentShader::New(const std::string& filePath)
	{
	#if $DIRECTX
		return new DirectX::FragmentShader(filePath);
	#else
	#error Unsupported graphics API.
	#endif
	}
}
