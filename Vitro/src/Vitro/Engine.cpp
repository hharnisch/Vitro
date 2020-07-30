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

	#if $WINDOWS
		Windows::API::Initialize();
	#else
	#error Unsupported system.
	#endif

	#if $DIRECTX
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
		LogEngineDebug(e);
		window.OnEvent(e);
		e.Dispatch<WindowCloseEvent>(Engine::OnWindowClose);
	}

	void Engine::OnWindowOpen(Window* window)
	{
		OpenWindows.emplace_back(window);
	}

	void Engine::Start()
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
