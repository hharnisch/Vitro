#include "Sandbox.h"

#include "TestLayer.h"

#include <Vitro.h>

void main(int argc, char** argv)
{
	auto app = new Sandbox::Sandbox(argc, argv);
	app->Start();
	delete app;
}

namespace Sandbox
{
	Sandbox::Sandbox(int argc, char** argv) : Engine(argc, argv)
	{
		auto w1 = Vitro::Window::New(1000, 800, 600, 300, "1");
		w1->Open();
		w1->Attach<UIOverlay>();
	}

	Sandbox::~Sandbox()
	{
	}
}
