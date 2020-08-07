#pragma once

#include "TriangleLayer.h"

#include <Vitro.h>

class TriangleTest : public Vitro::Engine
{
public:
	TriangleTest() : Engine("", "")
	{
		AppWindow1 = new Vitro::Window(550, 450, 300, 150, "TriangleTest 1");
		AppWindow2 = new Vitro::Window(550, 450, 1000, 150, "TriangleTest 2");
	}

	~TriangleTest()
	{
		delete AppWindow1;
		delete AppWindow2;
	}

	void OnStart() override
	{
		AppWindow1->Attach<TriangleLayer>();
		AppWindow1->Open();

		AppWindow2->Attach<TriangleLayer>();
		AppWindow2->Open();
	}

private:
	Vitro::Window* AppWindow1;
	Vitro::Window* AppWindow2;
};
