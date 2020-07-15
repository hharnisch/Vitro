#pragma once

#include "Sandbox.h"

namespace Sandbox
{
	using namespace Vitro;

	class TestLayer : public Vitro::Layer
	{
	public:
		void OnAttach() override
		{}

		void OnDetach() override
		{}

		void OnUpdate() override
		{}

		void OnEvent(Event& e) override
		{}
	};
}
