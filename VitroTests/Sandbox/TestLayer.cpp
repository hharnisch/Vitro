#include "TestLayer.h"

namespace Sandbox
{
	TestLayer::TestLayer() :
		Vertices(Triangle, 3),
		VShader("DefaultVertex.cso"),
		FShader("DefaultFragment.cso")
	{}

	void TestLayer::OnAttach()
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

	void TestLayer::OnDetach()
	{}

	void TestLayer::OnUpdate()
	{
		Vertices.Bind(Vitro::VertexTopology::TriangleList);
	}

	void TestLayer::OnEvent(Vitro::Event& e)
	{}
}
