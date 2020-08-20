#include "_pch.h"
#include "Engine.h"

#include "Vitro/Graphics/UI/UI.h"
#include "Vitro/Utility/Assert.h"
#include "Vitro/Utility/Log.h"

namespace Vitro
{
	Engine::Engine(const std::string& appLogPath, const std::string& engineLogPath)
	{
		AssertCritical(!Singleton, "Engine object has already been created.");
		Singleton = this;

		Log::Initialize(appLogPath, engineLogPath, LoggingThread);
		UI::Initialize();
	}

	Engine::~Engine()
	{
		IsShuttingDown = true;
		UI::Finalize();
		LoggingThread.join();
	}

	int Engine::Run()
	{
		try
		{
			AssertCritical(!ShouldTick, "Engine is already running.");
			ShouldTick = true;
			OnStart();
			StartTicking();
			return EXIT_SUCCESS;
		}
		catch(const std::exception& e)
		{
			LogEngineFatal(e.what());
			std::cin.get();
			return EXIT_FAILURE;
		}
	}

	float Engine::MeasureTime()
	{
		using namespace std::chrono;
		auto now = steady_clock::now().time_since_epoch();
		return static_cast<float>(duration_cast<nanoseconds>(now).count());
	}

	void Engine::StartTicking()
	{
		float previousTime = MeasureTime();
		while(ShouldTick)
		{
			float currentTime = MeasureTime();
			EngineTick = (currentTime - previousTime) / 1000000;
			previousTime = currentTime;
			for(auto window : OpenWindows)
			{
				window->OnTick(EngineTick);
				if(ResetTickToFirstWindow)
				{
					ResetTickToFirstWindow = false;
					break;
				}
			}
			PollEvents();
		}
	}

	void Engine::EraseWindow(Window& window)
	{
		auto i = std::find(OpenWindows.begin(), OpenWindows.end(), &window);
		OpenWindows.erase(i);

		ResetTickToFirstWindow = true;
		ShouldTick = OpenWindows.size();
	}

	void Engine::EmplaceWindow(Window& window)
	{
		OpenWindows.emplace_back(&window);
		ResetTickToFirstWindow = true;
	}
}
