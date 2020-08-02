#pragma once

#include <Vitro.h>

class SandboxLayer : public Vitro::Layer
{
public:
	SandboxLayer() :
		Vertices(Triangle, 3), VShader("SandboxVertex.cso"), FShader("SandboxFragment.cso")
	{}

	void OnAttach() override
	{
		using namespace Vitro;
		VertexField fields[]
		{
			VertexField(VertexField::Position, 0, VertexFieldType::Float3, 0),
			VertexField(VertexField::Color, 0, VertexFieldType::Float4, 12)
		};

		VShader.SetVertexLayout(fields, 2);
		VShader.Bind();
		FShader.Bind();
	}

	void OnDetach() override
	{}

	void OnUpdate() override
	{
		Vertices.Bind(Vitro::VertexTopology::TriangleList);
	}

	void OnEvent(Vitro::Event& e) override
	{}

private:
	struct Vertex
	{
		Vitro::Vec3 Position;
		Vitro::Vec4 Color;
	};

	Vertex Triangle[3]
	{
		{{0.f, 0.5f, 0.},		{1.f, 0.f, 0.f, 1.f}},
		{{0.5f, -0.5f, 0.},		{0.f, 1.f, 0.f, 1.f}},
		{{-0.5f, -0.5f, 0.},	{0.f, 0.f, 1.f, 1.f}}
	};

	Vitro::VertexBuffer<Vertex> Vertices;
	Vitro::VertexShader VShader;
	Vitro::FragmentShader FShader;
};
