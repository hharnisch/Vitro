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
		{
			auto r = []() { return rand() % 10 + 1; };
			Matrix3x4 m(4, 45, 6, 7, 817, 27, 8, 5, 8, 4, 7, 4);
			LogInfo(Transpose(m));
		}

		void OnEvent(Event& e) override
		{}
	};
}
