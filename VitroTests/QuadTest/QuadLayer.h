#pragma once

#include <Vitro.h>

class QuadLayer : public Vitro::Layer
{
public:
	QuadLayer() :
		Vertices(Quad, ArrayCount(Quad)), Indices(QuadIndices, ArrayCount(QuadIndices)),
		VShader("QuadVertex.cso"), FShader("QuadFragment.cso")
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
		VShader.SetVertexLayout(vl);
		VShader.Bind();
		FShader.Bind();
	}

	void OnDetach() override
	{}

	void OnUpdate() override
	{
		Vertices.Bind(Vitro::VertexTopology::TriangleList);
		Renderer->Submit(Indices);
	}

	void OnEvent(Vitro::Event& e) override
	{
		auto random = []() { return std::rand() / static_cast<float>(RAND_MAX); };

		using namespace Vitro;
		e.Dispatch<KeyDownEvent>([random, this](KeyDownEvent& e)
		{
			for(int i = 0; i < ArrayCount(Quad); i++)
				Quad[i].Color ={random(), random(), random(), random()};
			Vertices = VertexBuffer<Vertex>(Quad, ArrayCount(Quad));

			return true;
		});
	}

private:
	struct Vertex
	{
		Vitro::Float3 Position;
		Vitro::Float4 Color;
	};

	Vertex Quad[4]
	{
		{{-.5f, -.5f, 0.0},	{1.f, 0.f, 0.f, 1.f}},
		{{0.5f, 0.5f, 0.0},	{0.f, 1.f, 0.f, 1.f}},
		{{0.5f, -.5f, 0.0},	{1.f, 1.f, 0.f, 1.f}},
		{{-.5f, 0.5f, 0.0},	{0.f, 0.f, 1.f, 1.f}},
	};

	uint32_t QuadIndices[6]{0, 1, 2, 0, 3, 1};

	Vitro::VertexBuffer<Vertex> Vertices;
	Vitro::IndexBuffer Indices;
	Vitro::VertexShader VShader;
	Vitro::FragmentShader FShader;
};
