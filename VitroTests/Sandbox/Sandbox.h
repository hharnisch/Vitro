#pragma once

#include <Vitro.h>

class Sandbox : public Vitro::Engine
{
public:
	Sandbox() : Engine("", "")
	{
		AppWindow = new Vitro::Window(550, 450, 300, 150, "Sandbox");
	}

	~Sandbox()
	{
		delete AppWindow;
	}

	void OnStart() override
	{
		AppWindow->Open();
	}

private:
	Vitro::Window* AppWindow;
};
