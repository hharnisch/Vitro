Texture2D Ground;
SamplerState Sampler;

float4 main(float4 position : SV_POSITION, float2 tex0 : TEXCOORD0) : SV_TARGET
{
	float3 lightColor = (1, 0, 0, 1);
	float3 lightPos = (3, 3, 3);
	float3 lightDir = normalize(lightPos - position.xyz);

	float3 diffuse = lightColor * max(dot(norm, lightDir), 0);
	
	return Ground.Sample(Sampler, tex0);
}
