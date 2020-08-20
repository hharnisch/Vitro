#pragma once

#include <Vitro.h>

class TriangleLayer : public Vitro::Layer
{
public:
	TriangleLayer() :
		Vertices(Triangle, ArrayCount(Triangle)),
		Indices(TriangleIndices, ArrayCount(TriangleIndices)),
		VertexShader("TriangleVertex.cso"),
		FragmentShader("TriangleFragment.cso")
	{}

	void OnAttach() override
	{
		std::srand(static_cast<uint32_t>(time(nullptr)));

		using namespace Vitro;
		VertexLayout vl
		{
			{VertexField::Position, 0, VertexFieldType::Float3},
			{VertexField::Color,	0, VertexFieldType::Float4}
		};
		VertexShader.SetVertexLayout(vl);
		VertexShader.Bind();
		FragmentShader.Bind();
	}

	void OnDetach() override
	{}

	void OnTick(Vitro::Tick t) override
	{
		Vertices.Bind(Vitro::VertexTopology::TriangleList);
		Renderer->Submit(Indices);
	}

	void OnEvent(Vitro::Event& e) override
	{
		using namespace Vitro;

		auto random = []() { return std::rand() / static_cast<float>(RAND_MAX); };
		e.Dispatch<KeyDownEvent>([random, this](KeyDownEvent& e)
		{
			for(auto& vertex : Triangle)
				vertex.Color = {random(), random(), random(), random()};
			Vertices = VertexBuffer<Vertex>(Triangle, ArrayCount(Triangle));
			return true;
		});
	}

private:
	struct Vertex
	{
		Vitro::Float3 Position;
		Vitro::Float4 Color;
	};

	Vertex Triangle[3]
	{
		{{0.0f, 0.5f, 0.5},	{1.f, 0.f, 0.f, 1.f}},
		{{0.5f, -.5f, 0.5},	{0.f, 1.f, 0.f, 1.f}},
		{{-.5f, -.5f, 0.5},	{0.f, 0.f, 1.f, 1.f}}
	};

	uint32_t TriangleIndices[3] {0, 1, 2};

	Vitro::VertexBuffer<Vertex> Vertices;
	Vitro::IndexBuffer Indices;
	Vitro::VertexShader VertexShader;
	Vitro::FragmentShader FragmentShader;
};
