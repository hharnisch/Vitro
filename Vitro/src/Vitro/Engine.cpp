#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/OpenGL/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Diagnostics/Log.h"
#include "Vitro/Graphics/UI/UI.h"

namespace Vitro
{
	bool Engine::IsRunning;

	Engine::Engine(int argc, char** argv)
	{
	#if !$MULTIWINDOW
		MainWindow = nullptr;
	#endif

		IsRunning = true;
		Log::Initialize("", "");

	#if $WINDOWS
		Windows::API::Initialize();
	#else
	#error No valid build platform defined.
	#endif

	#if $OPENGL
		OpenGL::API::Initialize();
	#else
	#error No valid graphics API defined.
	#endif#

		UI::Initialize();
	}

	Engine::~Engine()
	{
		UI::Finalize();
	}

	bool Engine::Running()
	{
		return IsRunning;
	}

#if $MULTIWINDOW

	bool Engine::WindowIsClosing;
	std::vector<Window*> Engine::OpenWindows;
	std::unordered_map<uint64_t, Window*> Engine::OpenWindowIDs;

	void Engine::DispatchToWindow(uint64_t nativeID, Event& e)
	{
		LogEngineTrace(e);
		OpenWindowIDs[nativeID]->OnEvent(e);
		e.Dispatch<WindowCloseEvent>(Engine::OnWindowClose);
	}

	void Engine::OnWindowOpen(Window* window)
	{
		OpenWindows.emplace_back(window);
		OpenWindowIDs.emplace(window->GetNativeID(), window);
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
		Window* window = OpenWindowIDs[e.GetNativeID()];
		OpenWindowIDs.erase(e.GetNativeID());

		auto i = std::find(OpenWindows.begin(), OpenWindows.end(), window);
		OpenWindows.erase(i);
		WindowIsClosing = true;

		IsRunning = OpenWindows.size();
		return true;
	}

#else

	Window* Engine::MainWindow;

	void Engine::DispatchToWindow(uint64_t nativeID, Event& e)
	{
		MainWindow->OnEvent(e);
	}

	void Engine::OnWindowOpen(Window* window)
	{
		Assert(!MainWindow, "Other windows can only be created in multi-window builds.");
		MainWindow = window;
	}

	void Engine::Start()
	{
		while(IsRunning)
			MainWindow->Update();
	}

	bool Engine::OnWindowClose(WindowCloseEvent& e)
	{
		IsRunning = false;
		return true;
	}

#endif
}
