#pragma once

#include "SandboxLayer.h"

class Sandbox : public Vitro::Engine
{
public:
	Sandbox() : Engine("", "")
	{
		AppWindow = new Vitro::Window(550, 450, 300, 150, "TriangleTest");
	}

	~Sandbox()
	{
		delete AppWindow;
	}

	void OnStart() override
	{
		AppWindow->Attach<SandboxLayer>();
		AppWindow->Open();
	}

private:
	Vitro::Window* AppWindow;
};
