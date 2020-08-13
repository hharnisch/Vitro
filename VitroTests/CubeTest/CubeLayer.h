#pragma once

#include <Vitro.h>

class CubeLayer : public Vitro::Layer
{
public:
	CubeLayer(int width, int height) :
		Vertices(Cube, ArrayCount(Cube)),
		Indices(CubeIndices, ArrayCount(CubeIndices)),
		Uniforms(CamUniforms, 1),
		Cam({0, 3, -5}, Vitro::PerspectiveLH(0.4f * 3.14f, width, height, 1.0f, 1000.f)),
		VShader("CubeVertex.cso"),
		FShader("CubeFragment.cso")
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
		CamUniforms.MVP = Cam.GetProjection() * Cam.GetView();
		Vertices.Bind(VertexTopology::TriangleList);
		Uniforms.Update(CamUniforms);
		Uniforms.Bind();
		Renderer->Submit(Indices);
	}

	void OnEvent(Vitro::Event& e) override
	{
		using namespace Vitro;
		e.Dispatch<KeyDownEvent>([this](KeyDownEvent& e)
		{
			switch(e.GetKey())
			{
				case KeyCode::Q: Cam.AdjustPosition({+0.5, 0, 0}); break;
				case KeyCode::E: Cam.AdjustPosition({-0.5, 0, 0}); break;
				case KeyCode::D: Cam.AdjustPosition({0, +0.5, 0}); break;
				case KeyCode::A: Cam.AdjustPosition({0, -0.5, 0}); break;
				case KeyCode::W: Cam.AdjustPosition({0, 0, +0.5}); break;
				case KeyCode::S: Cam.AdjustPosition({0, 0, -0.5}); break;
				case KeyCode::R: Cam.SetPosition({0, 3, -5}); break;
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

	Vertex Cube[8]
	{
		{{-1.f, -1.f, -1.f}, {1.f, 0.f, 0.f, 1.f}},
		{{-1.f, +1.f, -1.f}, {1.f, 1.f, 0.f, 1.f}},
		{{+1.f, +1.f, -1.f}, {0.f, 1.f, 0.f, 1.f}},
		{{+1.f, -1.f, -1.f}, {0.f, 0.f, 1.f, 1.f}},
		{{-1.f, -1.f, +1.f}, {1.f, 0.f, 0.f, 1.f}},
		{{-1.f, +1.f, +1.f}, {1.f, 1.f, 0.f, 1.f}},
		{{+1.f, +1.f, +1.f}, {0.f, 1.f, 0.f, 1.f}},
		{{+1.f, -1.f, +1.f}, {0.f, 0.f, 1.f, 1.f}}
	};

	uint32_t CubeIndices[36]{0, 1, 2, 0, 2, 3,
							 4, 6, 5, 4, 7, 6,
							 4, 5, 1, 4, 1, 0,
							 3, 2, 6, 3, 6, 7,
							 1, 5, 6, 1, 6, 2,
							 4, 0, 3, 4, 3, 7};

	struct CameraUniforms
	{
		Vitro::Float4x4 MVP;
	};

	CameraUniforms CamUniforms;

	Vitro::Camera Cam;
	Vitro::VertexBuffer<Vertex> Vertices;
	Vitro::UniformBuffer<CameraUniforms> Uniforms;
	Vitro::IndexBuffer Indices;
	Vitro::VertexShader VShader;
	Vitro::FragmentShader FShader;
};
