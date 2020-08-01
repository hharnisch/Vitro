#include "Sandbox.h"

#include "TestLayer.h"

#include <Vitro.h>

namespace Sandbox
{
	Sandbox::Sandbox(int argc, char** argv) : Engine(argc, argv)
	{
		auto w1 = new Vitro::Window(800, 400, 0, 0, "Window 1");
		w1->Open();
		w1->Attach<TestLayer>();
	}

	Sandbox::~Sandbox()
	{}
}
