#include "CubeTest/CubeTest.h"
#include "TextureTest/TextureTest.h"
#include "TriangleTest/TriangleTest.h"

int main(int argc, char** argv)
{
	auto app = new CubeTest();
	int exitStatus = app->Run();
	delete app;
	return exitStatus;
}
