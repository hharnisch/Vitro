#include "_pch.h"
#include "VertexShader.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/FileUtils.h"

namespace Vitro::DirectX
{
	VertexShader::VertexShader(const std::string& filePath)
	{
		Bytecode = FileUtils::GetBinaryData(filePath);
		API::Device->CreateVertexShader(Bytecode.Raw(), Bytecode.Count(), nullptr, &ShaderPtr);
	}

	void VertexShader::Bind()
	{
		API::Context->VSSetShader(ShaderPtr.Get(), nullptr, 0);
	}

	void VertexShader::SetVertexLayout(VertexField fields[], uint32_t count)
	{
		auto ied = reinterpret_cast<D3D11_INPUT_ELEMENT_DESC*>(fields);
		Microsoft::WRL::ComPtr<ID3D11InputLayout> layout;
		API::Device->CreateInputLayout(ied, count, Bytecode.Raw(), Bytecode.Count(), &layout);
		API::Context->IASetInputLayout(layout.Get());
	}
}
