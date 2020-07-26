#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowCloseEvent.h"
#include "Vitro/Graphics/Window.h"

namespace Vitro
{
	class Engine
	{
	public:
		Engine(int argc, char** argv);
		virtual ~Engine();

		static bool Running();
		static void DispatchToWindow(Window& window, Event& e);
		static void OnWindowOpen(Window* window);

		void Start();

	private:
		static bool IsRunning;
		static bool WindowIsClosing;
		static std::vector<Window*> OpenWindows;

		static bool OnWindowClose(WindowCloseEvent& e);
	};
}
