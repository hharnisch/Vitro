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
		WindowMoveEvent(uint64_t nativeID, int width, int height);

		int GetX() const;
		int GetY() const;

		explicit operator std::string() const override;

	private:
		int X;
		int Y;
	};
}
