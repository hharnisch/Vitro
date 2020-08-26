#pragma once

#include "Vitro/Graphics/VertexLayout.h"
#include "Vitro/Utility/HeapArray.h"
#include "Vitro/Utility/Ref.h"

namespace Vitro
{
	class Shader : public RefCounted
	{
	public:
		virtual ~Shader() = default;
		virtual void Bind() const = 0;

		inline const HeapArray<char>& GetBytecode() const { return Bytecode; }

	protected:
		HeapArray<char> Bytecode;
	};

	class VertexShader : public Shader
	{
	public:
		static Ref<VertexShader> New(const std::string& filePath);

		virtual void SetVertexLayout(const VertexLayout& vl) = 0;
	};

	class FragmentShader : public Shader
	{
	public:
		static Ref<FragmentShader> New(const std::string& filePath);
	};
}
