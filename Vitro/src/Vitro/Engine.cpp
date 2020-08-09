#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Graphics/UI/UI.h"
#include "Vitro/Utility/Assert.h"
#include "Vitro/Utility/Log.h"

namespace Vitro
{
	Engine::Engine(const std::string& appLogPath, const std::string& engineLogPath)
	{
		static bool initialized;
		AssertCritical(!initialized, "Engine object has already been created.");

		Log::Initialize(appLogPath, engineLogPath, LoggingThread);

	#if VTR_SYSTEM_WINDOWS
		Windows::API::Initialize(Engine::DispatchToWindow);
	#else
	#error Unsupported system.
	#endif

	#if VTR_API_DIRECTX
		DirectX::API::Initialize();
	#else
	#error Unsupported graphics API.
	#endif

		UI::Initialize();

		initialized = true;
	}

	Engine::~Engine()
	{
		IsShuttingDown = true;
		UI::Finalize();

		LoggingThread.join();
	}

	bool Engine::Running()
	{
		return !IsShuttingDown;
	}

	int Engine::Run()
	{
		try
		{
			AssertCritical(!ShouldUpdate, "Engine has already been started.");
			OnStart();
			ShouldUpdate = true;

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

	void Engine::DispatchToWindow(Window& window, Event& e)
	{
		window.OnEvent(e);
		e.Dispatch<WindowCloseEvent>(Engine::OnWindowClose);
		e.Dispatch<WindowOpenEvent>(Engine::OnWindowOpen);
	}

	bool Engine::OnWindowClose(WindowCloseEvent& e)
	{
		auto window = std::find(OpenWindows.begin(), OpenWindows.end(), &e.GetWindow());
		OpenWindows.erase(window);

		ResetUpdateToFirstWindow = true;
		ShouldUpdate = OpenWindows.size();
		return true;
	}

	bool Engine::OnWindowOpen(WindowOpenEvent& e)
	{
		OpenWindows.emplace_back(&e.GetWindow());
		ResetUpdateToFirstWindow = true;
		return true;
	}
}
