#pragma once

#include "CubeLayer.h"

#include <Vitro.h>

class CubeTest : public Vitro::Engine
{
public:
	CubeTest() : Engine("", "")
	{
		AppWindow = new Vitro::Window(1200, 900, 300, 150, "CubeTest");
	}

	~CubeTest()
	{
		delete AppWindow;
	}

	void OnStart() override
	{
		AppWindow->Attach<CubeLayer>(AppWindow->GetWidth(), AppWindow->GetHeight());
		AppWindow->Open();
		AppWindow->TrapCursor(true);
	}

private:
	Vitro::Window* AppWindow;
};
