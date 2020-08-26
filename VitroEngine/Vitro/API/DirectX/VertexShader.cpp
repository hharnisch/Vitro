#include "_pch.h"
#include "VertexShader.h"

#include "Vitro/API/DirectX/RHI.h"
#include "Vitro/Utility/File.h"
#include "Vitro/Utility/StackArray.h"

namespace Vitro::DirectX
{
	VertexShader::VertexShader(const std::string& filePath)
	{
		Bytecode = File::LoadBinary(filePath);
		auto res = RHI::Device->CreateVertexShader(Bytecode.Raw(), Bytecode.Count(), nullptr,
												   &ShaderPtr);
		AssertCritical(SUCCEEDED(res), "Could not create vertex shader.");
	}

	void VertexShader::Bind() const
	{
		RHI::Context->VSSetShader(ShaderPtr, nullptr, 0);
	}

	void VertexShader::SetVertexLayout(const VertexLayout& vl)
	{
		StackArray<D3D11_INPUT_ELEMENT_DESC> ieds(vl.Count());

		auto src = vl.begin();
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

		Scope<ID3D11InputLayout> il;
		auto res = RHI::Device->CreateInputLayout(ieds.Raw(), static_cast<UINT>(ieds.Count()),
												  Bytecode.Raw(), Bytecode.Count(), &il);
		AssertCritical(SUCCEEDED(res), "Could not create vertex layout.");
		RHI::Context->IASetInputLayout(il);
	}
}
