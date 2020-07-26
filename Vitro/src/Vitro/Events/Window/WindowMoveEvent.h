#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowEvent.h"

namespace Vitro
{
	// Event fired when resizing a window.
	class WindowMoveEvent : public WindowEvent
	{
	public:
		$EventType(WindowMove);

		// Engine-internal constructor. Do NOT use in client application!
		WindowMoveEvent(Window& window, int width, int height);

		explicit operator std::string() const override;

		int GetX() const;
		int GetY() const;

	private:
		int X;
		int Y;
	};
}
