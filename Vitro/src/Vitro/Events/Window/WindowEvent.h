#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Graphics/Window.h"

namespace Vitro
{
	// Superclass for all window events.
	class WindowEvent : public Event
	{
	public:
		$EventSource(EventSource::App);

		explicit operator std::string() const override;

		Window& GetWindow();

	protected:
		Window& WindowRef;

		WindowEvent(Window& window);
	};
}
