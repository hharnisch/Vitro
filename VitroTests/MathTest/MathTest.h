#pragma once

#include "MathLayer.h"

#include <Vitro.h>

class MathTest : public Vitro::Engine
{
public:
	MathTest() : Engine("", "")
	{
		AppWindow = new Vitro::Window(250, 50, 400, 150, "MathTest");
	}

	~MathTest()
	{
		delete AppWindow;
	}

	void OnStart() override
	{
		AppWindow->Open();
		AppWindow->Attach<MathLayer>();
	}

private:
	Vitro::Window* AppWindow;
};
