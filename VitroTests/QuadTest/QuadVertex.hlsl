cbuffer cbPerObject
{
	float4x4 VP;
};

struct VOut
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

VOut main(float4 position : POSITION, float4 color : COLOR)
{
	VOut output;
	output.position = mul(position, VP);
	output.color = color;
	return output;
}
