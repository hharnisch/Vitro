#include "Sandbox/Sandbox.h"

void main(int argc, char** argv)
{
	auto app = new Sandbox::Sandbox(argc, argv);
	app->Start();
	delete app;
}
