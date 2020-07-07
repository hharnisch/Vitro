#include "_pch.h"
#include "Engine.h"

#include "Vitro/API/OpenGL/API.h"
#include "Vitro/API/Windows/API.h"
#include "Vitro/Diagnostics/Log.h"

#include <imgui/imgui.h>

namespace Vitro
{
	bool Engine::IsRunning;

	Engine::Engine(int argc, char** argv)
	{
		IsRunning = true;
		Log::Initialize("", "");

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

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

	std::vector<Window*> Engine::WindowList;
	std::unordered_map<uint64_t, Window*> Engine::WindowIDMap;

	Engine::~Engine()
	{
		for(Window* window : WindowList)
			delete window;
	}

	void Engine::DispatchToWindow(uint64_t nativeID, Event& e)
	{
		WindowIDMap[nativeID]->OnEvent(e);
	}

	void Engine::OnWindowOpen(uint64_t nativeID, Window* window)
	{
		WindowList.emplace_back(window);
		WindowIDMap.emplace(nativeID, window);
		IsRunning = WindowList.size();
	}

	void Engine::OnWindowClose(WindowCloseEvent& e)
	{
		Window* window = WindowIDMap[e.GetNativeID()];
		WindowIDMap.erase(e.GetNativeID());
		auto i = std::find(WindowList.begin(), WindowList.end(), window);
		WindowList.erase(i);
		IsRunning = WindowList.size();
	}

	void Engine::Start()
	{
		while(IsRunning)
			for(Window* window : WindowList)
				window->Update();
	}

#else

	Window* Engine::MainWindow;

	Engine::~Engine()
	{
		delete MainWindow;
	}

	void Engine::DispatchToWindow(uint64_t nativeID, Event& e)
	{
		MainWindow->OnEvent(e);
	}

	void Engine::OnWindowOpen(uint64_t nativeID, Window* window)
	{
		if(MainWindow)
			throw std::runtime_error("Other windows can only be created in multi-window builds.");
		MainWindow = window;
	}

	void Engine::OnWindowClose(WindowCloseEvent& e)
	{
		IsRunning = false;
	}

	void Engine::Start()
	{
		while(IsRunning)
			MainWindow->Update();
	}

#endif
}
