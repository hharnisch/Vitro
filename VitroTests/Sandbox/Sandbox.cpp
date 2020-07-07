#include "Sandbox.h"

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
		auto window = Vitro::Window::New(1000, 800, 600, 300, "1");
		window->Show();
		window->Attach(new Vitro::UIOverlay());
	}

	Sandbox::~Sandbox()
	{
	}
}
