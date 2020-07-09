#include "Sandbox.h"

#include <Vitro.h>
#include "TestLayer.h"

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
		w1->Attach<TestLayer>(w1);

		auto w2 = Vitro::Window::New(1000, 800, 700, 400, "2");
		w2->Open();
		w2->Attach<TestLayer>(w2);

		auto w3 = Vitro::Window::New(1000, 800, 800, 500, "3");
		w3->Open();
		w3->Attach<TestLayer>(w3);
	}

	Sandbox::~Sandbox()
	{
	}
}
