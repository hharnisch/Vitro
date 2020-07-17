#include "Sandbox.h"

#include "TestLayer.h"

#include <Vitro.h>

namespace Sandbox
{
	Sandbox::Sandbox(int argc, char** argv) : Engine(argc, argv)
	{
		auto w1 = Vitro::Window::New(1000, 800, 600, 300, "Window 1");
		w1->Open();
		w1->Attach<TestLayer>();
		w1->Attach<UIOverlay>();
	}

	Sandbox::~Sandbox()
	{}
}
