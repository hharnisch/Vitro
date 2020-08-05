#pragma once

#include "QuadLayer.h"

#include <Vitro.h>

class QuadTest : public Vitro::Engine
{
public:
	QuadTest() : Engine("", "")
	{
		AppWindow1 = new Vitro::Window(550, 450, 300, 150, "QuadTest 1");
		AppWindow2 = new Vitro::Window(550, 450, 1000, 150, "QuadTest 2");
	}

	~QuadTest()
	{
		delete AppWindow1;
		delete AppWindow2;
	}

	void OnStart() override
	{
		AppWindow1->Open();
		AppWindow1->Attach<QuadLayer>();

		AppWindow2->Open();
		AppWindow2->Attach<QuadLayer>();
	}

private:
	Vitro::Window* AppWindow1;
	Vitro::Window* AppWindow2;
};
