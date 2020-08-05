#include "QuadTest/QuadTest.h"
#include "TriangleTest/TriangleTest.h"

int main(int argc, char** argv)
{
	auto app = new TriangleTest();
	int exitStatus = app->Run();
	delete app;
	return exitStatus;
}
