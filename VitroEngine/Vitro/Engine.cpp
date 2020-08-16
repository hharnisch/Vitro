#include "_pch.h"
#include "Engine.h"

#include "Vitro/Graphics/UI/UI.h"
#include "Vitro/Utility/Assert.h"
#include "Vitro/Utility/Log.h"

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/API.h"
#endif

namespace Vitro
{
	Engine::Engine(const std::string& appLogPath, const std::string& engineLogPath)
	{
		AssertCritical(!Singleton, "Engine object has already been created.");
		Singleton = this;

		Log::Initialize(appLogPath, engineLogPath, LoggingThread);

	#if VTR_SYSTEM_WINDOWS
		Windows::API::Initialize();
	#else
	#error Unsupported system.
	#endif

	#if VTR_API_DIRECTX
		DirectX::API::Initialize();
	#else
	#error Unsupported graphics API.
	#endif

		UI::Initialize();
	}

	Engine::~Engine()
	{
		IsShuttingDown = true;
		UI::Finalize();
		LoggingThread.join();
	}

	Engine& Engine::Get()
	{
		return *Singleton;
	}

	bool Engine::IsRunning()
	{
		return !IsShuttingDown;
	}

	int Engine::Run()
	{
		try
		{
			AssertCritical(!ShouldUpdate, "Engine has already been started.");
			ShouldUpdate = true;
			OnStart();
			while(ShouldUpdate)
				for(auto window : OpenWindows)
				{
					window->Update();
					if(ResetUpdateToFirstWindow)
					{
						ResetUpdateToFirstWindow = false;
						break;
					}
				}
			return EXIT_SUCCESS;
		}
		catch(const std::exception& e)
		{
			LogEngineFatal(e.what());
			std::cin.get();
			return EXIT_FAILURE;
		}
	}

	void Engine::OnWindowClose(WindowCloseEvent& e)
	{
		auto window = std::find(OpenWindows.begin(), OpenWindows.end(), &e.GetWindow());
		OpenWindows.erase(window);

		ResetUpdateToFirstWindow = true;
		ShouldUpdate = OpenWindows.size();
	}

	void Engine::OnWindowOpen(WindowOpenEvent& e)
	{
		OpenWindows.emplace_back(&e.GetWindow());
		ResetUpdateToFirstWindow = true;
	}
}
