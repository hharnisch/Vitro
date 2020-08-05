#pragma once

#include "_pch.h"
#include "Vitro/Utility/HeapArray.h"

namespace Vitro::Base
{
	class Shader
	{
	public:
		virtual void Bind() = 0;

		const HeapArray<char>& GetBytecode() const { return Bytecode; }

	protected:
		HeapArray<char> Bytecode;
	};
}
