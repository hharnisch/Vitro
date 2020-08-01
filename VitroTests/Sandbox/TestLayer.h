#pragma once

#include <Vitro.h>

namespace Sandbox
{
	class TestLayer : public Vitro::Layer
	{
	public:
		TestLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Vitro::Event& e) override;

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
}
