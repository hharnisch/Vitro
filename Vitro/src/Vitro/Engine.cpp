#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/OpenGL/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Diagnostics/Log.h"
#include "Vitro/Events/Input.h"

#include <imgui/imgui.h>

namespace Vitro
{
	bool Engine::IsRunning;

	Engine::Engine(int argc, char** argv)
	{
	#if $MULTIWINDOW
		OpenWindows.insert(OpenWindows.begin(), nullptr);
	#else
		MainWindow = nullptr;
	#endif

		IsRunning = true;
		Log::Initialize("", "");

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = nullptr;

	#if $WINDOWS
		Windows::API::Initialize();
	#else
	#error No valid build platform defined.
	#endif

	#if $OPENGL
		OpenGL::API::Initialize();
	#else
	#error No valid graphics API defined.
	#endif
	}

	bool Engine::Running()
	{
		return IsRunning;
	}

#if $MULTIWINDOW

	std::vector<Window*> Engine::OpenWindows;
	std::vector<Window*>::iterator Engine::FirstWindow;
	std::vector<Window*>::iterator Engine::NextWindow;
	std::unordered_map<uint64_t, Window*> Engine::OpenWindowIDs;

	void Engine::DispatchToWindow(uint64_t nativeID, Event& e)
	{
		OpenWindowIDs[nativeID]->OnEvent(e);
	}

	void Engine::OnWindowOpen(Window* window)
	{
		OpenWindows.emplace_back(window);
		FirstWindow = OpenWindows.begin() + 1;
		OpenWindowIDs.emplace(window->GetNativeID(), window);
	}

	bool Engine::OnWindowClose(WindowCloseEvent& e)
	{
		Window* window = OpenWindowIDs[e.GetNativeID()];
		OpenWindowIDs.erase(e.GetNativeID());

		auto i = std::find(OpenWindows.begin(), OpenWindows.end(), window);
		OpenWindows.erase(i);
		NextWindow = OpenWindows.begin();

		IsRunning = OpenWindows.size() > 1;
		return true;
	}

	void Engine::Start()
	{
		while(IsRunning)
		{
			NextWindow = FirstWindow;
			while(NextWindow != OpenWindows.end())
			{
				(*NextWindow)->Update();
				NextWindow++;
			}
		}
	}

#else

	Window* Engine::MainWindow;

	void Engine::DispatchToWindow(uint64_t nativeID, Event& e)
	{
		MainWindow->OnEvent(e);
	}

	void Engine::OnWindowOpen(Window* window)
	{
		if(MainWindow)
			throw std::runtime_error("Other windows can only be created in multi-window builds.");
		MainWindow = window;
	}

	bool Engine::OnWindowClose(WindowCloseEvent& e)
	{
		IsRunning = false;
		return true;
	}

	void Engine::Start()
	{
		while(IsRunning)
			MainWindow->Update();
	}

#endif
}
