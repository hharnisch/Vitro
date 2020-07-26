#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/DirectX/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Diagnostics/Log.h"
#include "Vitro/Graphics/UI/UI.h"

namespace Vitro
{
	bool Engine::IsRunning;
	bool Engine::WindowIsClosing;
	std::vector<Window*> Engine::OpenWindows;

	Engine::Engine(int argc, char** argv)
	{
		IsRunning = true;
		Log::Initialize("", "");

	#if $WINDOWS
		Windows::API::Initialize();
	#else
	#error No valid build platform defined.
	#endif

	#if $DIRECTX
		DirectX::API::Initialize();
	#else
	#error No valid graphics API defined.
	#endif

		UI::Initialize();
	}

	Engine::~Engine()
	{
		UI::Finalize();
	#if $DIRECTX
		DirectX::API::Finalize();
	#endif
	}

	bool Engine::Running()
	{
		return IsRunning;
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

	void Engine::Start()
	{
		while(IsRunning)
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

		IsRunning = OpenWindows.size();
		return true;
	}
}
