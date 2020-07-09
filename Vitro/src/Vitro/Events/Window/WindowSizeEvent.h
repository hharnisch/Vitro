#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/Window/WindowEvent.h"

namespace Vitro
{
	// Event fired when resizing a window.
	class WindowSizeEvent : public WindowEvent
	{
	public:
		$EventType(WindowSize);

		// Engine-internal constructor. Do NOT use in client application!
		WindowSizeEvent(uint64_t nativeID, int width, int height);

		explicit operator std::string() const override;

		int GetWidth() const;
		int GetHeight() const;

	private:
		int Width;
		int Height;
	};
}
