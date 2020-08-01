#pragma once

#include "_pch.h"
#include "Vitro/Utility/Array.h"

namespace Vitro::Base
{
	class Shader
	{
	public:
		virtual void Bind() = 0;

		const Array<char>& GetBytecode() const;

	protected:
		Array<char> Bytecode;
	};
}
