#pragma once

#include "Sandbox.h"

namespace Sandbox
{
	using namespace Vitro;

	class TestLayer : public Vitro::Layer
	{
	public:
		Window* OwnedWindow;

		TestLayer(Window* w) : OwnedWindow(w)
		{
		}

		void OnAttach() override
		{
		}

		void OnDetach() override
		{
		}

		void OnUpdate() override
		{
		}

		void OnEvent(Event& e) override
		{
			e.Dispatch<KeyUpEvent>([this](KeyUpEvent& e)
			{
				if(e.GetKeyCode() == KeyCode::P)
				{
					OwnedWindow->Close();
					delete OwnedWindow;
				}

				return true;
			});
		}
	};
}
