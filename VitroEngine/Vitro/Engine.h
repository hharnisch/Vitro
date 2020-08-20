#pragma once

#include "Vitro/Graphics/Window.h"

#if VTR_SYSTEM_WINDOWS
#include "Vitro/API/Windows/ApplicationBase.h"
#endif

namespace Vitro
{
#if VTR_SYSTEM_WINDOWS
	typedef Windows::ApplicationBase ApplicationBase;
#endif

	class Engine : public ApplicationBase
	{
	public:
		Engine(const std::string& appLogPath, const std::string& engineLogPath);
		virtual ~Engine();

		static inline Engine& Get() { return *Singleton; }
		inline bool IsRunning() { return !IsShuttingDown; }
		inline Tick GetTick() { return EngineTick; }

		virtual void OnStart() = 0;

		int Run();

		Engine(const Engine&) = delete;
		Engine(Engine&&) = delete;
		Engine& operator=(const Engine&) = delete;
		Engine& operator=(Engine&&) = delete;

	private:
		static inline Engine* Singleton;

		bool ShouldTick {};
		bool IsShuttingDown {};
		bool ResetTickToFirstWindow {};
		Tick EngineTick;
		std::thread LoggingThread;
		std::vector<Window*> OpenWindows;

		float MeasureTime();
		void StartTicking();
		void EraseWindow(Window& window) final override;
		void EmplaceWindow(Window& window) final override;
	};
}
