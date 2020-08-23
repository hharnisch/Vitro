#pragma once

#include "_pch.h"
#include "Vitro/Utility/HeapArray.h"
#include "Vitro/Utility/Ref.h"

namespace Vitro
{
	class Shader : public RefCounted
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() = 0;

		inline const HeapArray<char>& GetBytecode() const
		{
			return Bytecode;
		}

	protected:
		HeapArray<char> Bytecode;
	};
}
