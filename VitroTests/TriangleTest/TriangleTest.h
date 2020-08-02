#pragma once

#include "TriangleLayer.h"

#include <Vitro.h>

class TriangleTest : public Vitro::Engine
{
public:
	TriangleTest() : Engine("", "")
	{
		AppWindow = new Vitro::Window(550, 450, 300, 150, "TriangleTest");
	}

	~TriangleTest()
	{
		delete AppWindow;
	}

	void OnStart() override
	{
		AppWindow->Attach<TriangleLayer>();
		AppWindow->Open();
	}

private:
	Vitro::Window* AppWindow;
};
