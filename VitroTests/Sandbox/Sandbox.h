#pragma once

#include <Vitro.h>

void main(int argc, char** argv);

namespace Sandbox
{
	class Sandbox : public Vitro::Engine
	{
	public:
		Sandbox(int argc, char** argv);
		~Sandbox();
	};
}
