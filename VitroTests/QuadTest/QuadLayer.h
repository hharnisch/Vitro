#pragma once

#include <Vitro.h>

class QuadLayer : public Vitro::Layer
{
public:
	QuadLayer(int width, int height) :
		Vertices(Quad, ArrayCount(Quad)), Indices(QuadIndices, ArrayCount(QuadIndices)),
		UniformBuf(VP, 1), Cam(Vitro::Perspective<float>(0.78f, width, height, 0.1f, 100.f)),
		VShader("QuadVertex.cso"), FShader("QuadFragment.cso")
	{}

	void OnAttach() override
	{
		using namespace Vitro;
		std::srand(static_cast<uint32_t>(time(nullptr)));
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
		using namespace Vitro;
		VP.ViewProjection = Cam.GetProjection() * Cam.GetView();
		Vertices.Bind(VertexTopology::TriangleList);
		UniformBuf.Update(VP);
		UniformBuf.Bind();
		Renderer->Submit(Indices);
	}

	void OnEvent(Vitro::Event& e) override
	{
		using namespace Vitro;
		e.Dispatch<KeyDownEvent>([this](KeyDownEvent& e)
		{
			switch(e.GetKey())
			{
				case KeyCode::X: Cam.AdjustPosition({0.1, 0, 0}); break;
				case KeyCode::C: Cam.AdjustPosition({-.1, 0, 0}); break;
				case KeyCode::Y: Cam.AdjustPosition({0, 0.1, 0}); break;
				case KeyCode::A: Cam.AdjustPosition({0, -.1, 0}); break;
				case KeyCode::Z: Cam.AdjustPosition({0, 0, 0.1}); break;
				case KeyCode::T: Cam.AdjustPosition({0, 0, -.1}); break;
			}
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
		{{-.5f, -.5f, 0.5f}, {1.0f, 0.0f, 0.0f, 1.0f}},
		{{-.5f,  .5f, 0.5f}, {0.0f, 1.0f, 0.0f, 1.0f}},
		{{0.5f,  .5f, 0.5f}, {0.0f, 0.0f, 1.0f, 1.0f}},
		{{0.5f, -.5f, 0.5f}, {0.0f, 1.0f, 0.0f, 1.0f}},
	};

	uint32_t QuadIndices[6]{0, 1, 2, 0, 2, 3};

	struct Uniforms
	{
		Vitro::Float4x4 ViewProjection;
	};

	Uniforms VP;

	Vitro::Camera Cam;
	Vitro::VertexBuffer<Vertex> Vertices;
	Vitro::UniformBuffer<Uniforms> UniformBuf;
	Vitro::IndexBuffer Indices;
	Vitro::VertexShader VShader;
	Vitro::FragmentShader FShader;
};
