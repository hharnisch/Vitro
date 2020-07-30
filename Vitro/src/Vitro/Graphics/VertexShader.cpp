#include "_pch.h"
#include "VertexShader.h"

#include "Vitro/API/DirectX/VertexShader.h"

namespace Vitro
{
	VertexShader* VertexShader::New(const std::string& filePath)
	{
	#if $DIRECTX
		return new DirectX::VertexShader(filePath);
	#else
	#error Unsupported graphics API.
	#endif
	}
}
