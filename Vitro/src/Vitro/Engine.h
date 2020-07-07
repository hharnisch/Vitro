#pragma once

#include "Vitro/Events/Event.h"
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

		static void OnWindowOpen(uint64_t nativeID, Window* window);
		static void OnWindowClose(WindowCloseEvent& e);

		void Start();

	private:
		static bool IsRunning;

	#if $MULTIWINDOW
		static std::vector<Window*> WindowList;
		static std::unordered_map<uint64_t, Window*> WindowIDMap;
	#else
		static Window* MainWindow;
	#endif
	};
}
