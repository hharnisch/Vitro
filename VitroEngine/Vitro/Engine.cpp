#include "_pch.h"
#include "Engine.h"

#include "Vitro/Graphics/UI/UI.h"
#include "Vitro/Utility/Assert.h"
#include "Vitro/Utility/Log.h"

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/RHI.h"
#endif

namespace Vitro
{
	Engine::Engine(const std::string& appLogPath, const std::string& engineLogPath)
	{
		AssertCritical(!Singleton, "Engine object has already been created.");
		Singleton = this;

		Log::Initialize(appLogPath, engineLogPath, LoggingThread);

	#if VTR_API_DIRECTX
		DirectX::RHI::Initialize();
	#endif

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

	uint64_t Engine::MeasureTime()
	{
		using namespace std::chrono;
		auto now = steady_clock::now().time_since_epoch();
		return duration_cast<microseconds>(now).count();
	}

	void Engine::StartTicking()
	{
		uint64_t previousTime = MeasureTime();
		while(ShouldTick)
		{
			uint64_t currentTime = MeasureTime();
			EngineTick = (currentTime - previousTime) / 1000000.0f;
			previousTime = currentTime;
			for(auto& window : OpenWindows)
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

	void Engine::EraseOpenWindow(Window& window)
	{
		auto i = std::find(OpenWindows.begin(), OpenWindows.end(), Ref(&window));
		OpenWindows.erase(i);

		ResetTickToFirstWindow = true;
		ShouldTick = OpenWindows.size();
	}

	void Engine::EmplaceOpenWindow(Window& window)
	{
		OpenWindows.emplace_back(Ref(&window));
		ResetTickToFirstWindow = true;
	}
}
