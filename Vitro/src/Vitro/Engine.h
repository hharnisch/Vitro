#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowCloseEvent.h"
#include "Vitro/Events/Window/WindowOpenEvent.h"
#include "Vitro/Graphics/Window.h"

namespace Vitro
{
	class Engine
	{
	public:
		Engine(const std::string& appLogPath, const std::string& engineLogPath);
		virtual ~Engine();

		static bool Running();

		virtual void OnStart() = 0;

		int Start();

	private:
		static bool ShouldUpdate;
		static bool IsShuttingDown;
		static bool WindowIsClosing;
		static std::vector<Window*> OpenWindows;
		static std::thread LoggingThread;

		static void DispatchToWindow(Window& window, Event& e);
		static bool OnWindowOpen(WindowOpenEvent& e);
		static bool OnWindowClose(WindowCloseEvent& e);
	};
}
