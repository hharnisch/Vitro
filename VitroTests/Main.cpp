#include "Sandbox/Sandbox.h"

int main(int argc, char** argv)
{
	auto app = new Sandbox::Sandbox(argc, argv);
	int exitStatus = app->Start();
	delete app;
	return exitStatus;
}
