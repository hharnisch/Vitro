#pragma once

#include <Vitro.h>

class CubeLayer : public Vitro::Layer
{
public:
	CubeLayer(int width, int height) :
		Vertices(Cube, ArrayCount(Cube)),
		Indices(CubeIndices, ArrayCount(CubeIndices)),
		Uniforms(CamUniforms, 1),
		Cam({0, 3, -3}, Vitro::Perspective(0.4f * 3.14f, width, height, 1.0f, 1000.f)),
		VShader("CubeVertex.cso"),
		FShader("CubeFragment.cso")
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
		using namespace Vitro;
		CamUniforms.MVP = Cam.GetProjection() * Cam.GetView();
		Vertices.Bind(VertexTopology::TriangleList);
		Uniforms.Update(CamUniforms);
		Uniforms.Bind();
		Renderer->Submit(Indices);

		CamUniforms.MVP = Translate(Cam.GetProjection() * Cam.GetView(), {2.5, 2.5, 2.5});
		Vertices.Bind(VertexTopology::TriangleList);
		Uniforms.Update(CamUniforms);
		Uniforms.Bind();
		Renderer->Submit(Indices);

		if(Input::IsDown(KeyCode::A))
			Cam.Translate({-0.25, 0, 0});
		if(Input::IsDown(KeyCode::D))
			Cam.Translate({+0.25, 0, 0});

		if(Input::IsDown(KeyCode::Q))
			Cam.Translate({0, -0.25, 0});
		if(Input::IsDown(KeyCode::E))
			Cam.Translate({0, +0.25, 0});

		if(Input::IsDown(KeyCode::S))
			Cam.Translate({0, 0, -0.25});
		if(Input::IsDown(KeyCode::W))
			Cam.Translate({0, 0, +0.25});

		if(Input::IsDown(KeyCode::R))
			Cam.SetPosition({0, 3, -3});
	}

	void OnEvent(Vitro::Event& e) override
	{
		auto random = []() { return std::rand() / static_cast<float>(RAND_MAX); };

		using namespace Vitro;
		e.Dispatch<MouseUpEvent>([random, this](MouseUpEvent& e)
		{
			for(auto& vertex : Cube)
				vertex.Color ={random(), random(), random(), random()};
			Vertices = VertexBuffer<Vertex>(Cube, ArrayCount(Cube));
			return true;
		});

		e.Dispatch<MouseMoveEvent>([this](MouseMoveEvent& e)
		{
			if(Input::IsDown(KeyCode::Tab))
				Cam.Pitch(e.GetX() / 10000.f);
			if(Input::IsDown(KeyCode::Space))
				Cam.Yaw(e.GetY() / 10000.f);
			if(Input::IsDown(KeyCode::Alt))
				Cam.Roll(e.GetX() / 10000.f);
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
