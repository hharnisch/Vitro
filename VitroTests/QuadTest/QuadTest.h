#pragma once

#include "QuadLayer.h"

#include <Vitro.h>

class QuadTest : public Vitro::Engine
{
public:
	QuadTest() : Engine("", "")
	{
		AppWindow = new Vitro::Window(550, 450, 300, 150, "QuadTest");
	}

	~QuadTest()
	{
		delete AppWindow;
	}

	void OnStart() override
	{
		AppWindow->Attach<QuadLayer>(550, 450);
		AppWindow->Open();
	}

private:
	Vitro::Window* AppWindow;
};
