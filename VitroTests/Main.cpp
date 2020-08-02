#include "TriangleTest/TriangleTest.h"

int main(int argc, char** argv)
{
	auto app = new TriangleTest();
	int exitStatus = app->Start();
	delete app;
	return exitStatus;
}
