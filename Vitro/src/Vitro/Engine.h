#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/WindowEvent.h"
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

		int Run();

	private:
		static inline bool ShouldUpdate, IsShuttingDown, ResetUpdateToFirstWindow;
		static inline std::vector<Window*> OpenWindows;
		static inline std::thread LoggingThread;

		static void DispatchToWindow(Window& window, Event& e);
		static bool OnWindowClose(WindowCloseEvent& e);
		static bool OnWindowOpen(WindowOpenEvent& e);
	};
}
