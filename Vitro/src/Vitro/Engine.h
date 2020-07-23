#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowCloseEvent.h"
#include "Vitro/Graphics/Window.h"

namespace Vitro
{
	class Engine
	{
	public:
		Engine(int argc, char** argv);
		virtual ~Engine();

		static bool Running();
		static void DispatchToWindow(uint64_t nativeID, Event& e);
		static void OnWindowOpen(Window* window);

		void Start();

	private:
		static bool IsRunning;

	#if $MULTIWINDOW
		static bool WindowIsClosing;
		static std::vector<Window*> OpenWindows;
		static std::unordered_map<uint64_t, Window*> OpenWindowIDs;
	#else
		static Window* MainWindow;
	#endif

		static bool OnWindowClose(WindowCloseEvent& e);
	};
}
