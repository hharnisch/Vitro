#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Graphics/UI/UI.h"
#include "Vitro/Utility/Log.h"

namespace Vitro
{
	bool Engine::ShouldUpdate;
	bool Engine::IsShuttingDown;
	bool Engine::WindowIsClosing;
	std::vector<Window*> Engine::OpenWindows;
	std::thread Engine::LoggingThread;

	Engine::Engine(int argc, char** argv)
	{
		Log::Initialize("", "", LoggingThread);

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

	bool Engine::Running()
	{
		return !IsShuttingDown;
	}

	void Engine::DispatchToWindow(Window& window, Event& e)
	{
		LogEngineTrace(e);
		window.OnEvent(e);
		e.Dispatch<WindowCloseEvent>(Engine::OnWindowClose);
	}

	void Engine::OnWindowOpen(Window* window)
	{
		OpenWindows.emplace_back(window);
	}

	int Engine::Start()
	{
		try
		{
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
			return EXIT_FAILURE;
		}
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
