#include "_pch.h"
#include "Shader.h"

namespace Vitro::Base
{
	const Array<char>& Shader::GetBytecode() const
	{
		return Bytecode;
	}
}
