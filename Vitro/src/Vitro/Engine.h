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
		virtual ~Engine() = default;

		static bool Running();
		static void DispatchToWindow(uint64_t nativeID, Event& e);
		static void OnWindowOpen(Window* window);
		static bool OnWindowClose(WindowCloseEvent& e);

		void Start();

	private:
		static bool IsRunning;

	#if $MULTIWINDOW
		static std::vector<Window*> OpenWindows;
		static std::vector<Window*>::iterator FirstWindow;
		static std::vector<Window*>::iterator NextWindow;
		static std::unordered_map<uint64_t, Window*> OpenWindowIDs;
	#else
		static Window* MainWindow;
	#endif
	};
}
