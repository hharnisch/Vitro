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

		auto src = layout.begin();
		for(auto dst = ieds.begin(); dst != ieds.end(); ++src, ++dst)
		{
			(*dst).SemanticName			= (*src).Name.c_str();
			(*dst).SemanticIndex		= (*src).Index;
			(*dst).Format				= static_cast<DXGI_FORMAT>((*src).Type);
			(*dst).InputSlot			= 0;
			(*dst).AlignedByteOffset	= (*src).Offset;
			(*dst).InputSlotClass		= D3D11_INPUT_PER_VERTEX_DATA;
			(*dst).InstanceDataStepRate	= 0;
		}

		Microsoft::WRL::ComPtr<ID3D11InputLayout> layoutPtr;
		auto result = API::Device->CreateInputLayout(ieds.Raw(), static_cast<UINT>(ieds.Count()),
													 Bytecode.Raw(), Bytecode.Count(), &layoutPtr);
		AssertCritical(SUCCEEDED(result), "Could not create vertex layout.");
		API::Context->IASetInputLayout(layoutPtr.Get());
	}
}
