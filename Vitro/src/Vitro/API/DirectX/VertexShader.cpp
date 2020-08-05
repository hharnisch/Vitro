#include "_pch.h"
#include "VertexShader.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/Utility/FileUtils.h"
#include "Vitro/Utility/StackArray.h"

namespace Vitro::DirectX
{
	VertexShader::VertexShader(const std::string& filePath)
	{
		Bytecode = FileUtils::GetBinaryData(filePath);
		auto result = API::Device->CreateVertexShader(Bytecode.Raw(), Bytecode.Count(), nullptr,
													  &ShaderPtr);
		AssertCritical(SUCCEEDED(result), "Could not create vertex shader.");
	}

	void VertexShader::Bind()
	{
		API::Context->VSSetShader(ShaderPtr.Get(), nullptr, 0);
	}

	void VertexShader::SetVertexLayout(const VertexLayout& layout)
	{
		StackArray<D3D11_INPUT_ELEMENT_DESC> ieds(layout.Count());
		for(int i = 0; i < ieds.Count(); i++)
		{
			ieds[i].SemanticName			= layout[i].Name.c_str();
			ieds[i].SemanticIndex			= layout[i].Index;
			ieds[i].Format					= static_cast<DXGI_FORMAT>(layout[i].Type);
			ieds[i].InputSlot				= 0;
			ieds[i].AlignedByteOffset		= layout[i].Offset;
			ieds[i].InputSlotClass			= D3D11_INPUT_PER_VERTEX_DATA;
			ieds[i].InstanceDataStepRate	= 0;
		}

		Microsoft::WRL::ComPtr<ID3D11InputLayout> layoutPtr;
		auto result = API::Device->CreateInputLayout(ieds.Raw(), static_cast<UINT>(ieds.Count()),
													 Bytecode.Raw(), Bytecode.Count(), &layoutPtr);
		Assert(SUCCEEDED(result), "Could not create vertex layout.");
		API::Context->IASetInputLayout(layoutPtr.Get());
	}
}
