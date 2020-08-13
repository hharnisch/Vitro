#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/WindowEvent.h"
#include "Vitro/Graphics/Window.h"

#if VTR_SYSTEM_WINDOWS
#include "Vitro/API/Windows/API.h"
#endif

namespace Vitro
{
	class Engine
	{
	#if VTR_SYSTEM_WINDOWS
		friend class Windows::API;
	#endif

	public:
		Engine(const std::string& appLogPath, const std::string& engineLogPath);
		virtual ~Engine();

		static Engine& Get();

		virtual void OnStart() = 0;

		int Run();
		bool IsRunning();

	private:
		static inline Engine* Singleton;

		bool ShouldUpdate{};
		bool IsShuttingDown{};
		bool ResetUpdateToFirstWindow{};
		std::vector<Window*> OpenWindows;
		std::thread LoggingThread;

		void OnWindowClose(WindowCloseEvent& e);
		void OnWindowOpen(WindowOpenEvent& e);

		Engine(const Engine&) = delete;
		Engine(Engine&&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine& operator=(Engine&&) = delete;
	};
}
