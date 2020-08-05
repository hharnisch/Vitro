#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Graphics/UI/UI.h"
#include "Vitro/Utility/Assert.h"
#include "Vitro/Utility/Log.h"

namespace Vitro
{
	bool Engine::ShouldUpdate = false;
	bool Engine::IsShuttingDown = false;
	bool Engine::WindowIsClosing = false;
	std::vector<Window*> Engine::OpenWindows;
	std::thread Engine::LoggingThread;

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
				for(Window* window : OpenWindows)
				{
					window->Update();
					if(WindowIsClosing)
					{
						WindowIsClosing = false;
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
		LogEngineTrace(e);
		window.OnEvent(e);
		e.Dispatch<WindowOpenEvent>(Engine::OnWindowOpen);
		e.Dispatch<WindowCloseEvent>(Engine::OnWindowClose);
	}

	bool Engine::OnWindowOpen(WindowOpenEvent& e)
	{
		OpenWindows.emplace_back(&e.GetWindow());
		return true;
	}

	bool Engine::OnWindowClose(WindowCloseEvent& e)
	{
		auto i = std::find(OpenWindows.begin(), OpenWindows.end(), &e.GetWindow());
		OpenWindows.erase(i);
		WindowIsClosing = true;

		ShouldUpdate = OpenWindows.size();
		return true;
	}
}
