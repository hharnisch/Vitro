#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Graphics/Window.h"

namespace Vitro
{
	// Superclass for all window events.
	class WindowEvent : public Event
	{
	public:
		VTR_EVENT_SOURCE(EventSource::App);

		explicit operator std::string() const override;

		Window& GetWindow();

	protected:
		Window& WindowRef;

		WindowEvent(Window& window);
	};

	// Event fired when closing a window.
	class WindowCloseEvent : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowClose);

		// Engine-internal constructor. Do NOT use in client application!
		WindowCloseEvent(Window& window);
	};

	// Event fired when resizing a window.
	class WindowMoveEvent : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowMove);

		// Engine-internal constructor. Do NOT use in client application!
		WindowMoveEvent(Window& window, int width, int height);

		explicit operator std::string() const override;

		int GetX() const;
		int GetY() const;

	private:
		int X, Y;
	};

	// Event fired when resizing a window.
	class WindowSizeEvent : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowSize);

		// Engine-internal constructor. Do NOT use in client application!
		WindowSizeEvent(Window& window, int width, int height);

		explicit operator std::string() const override;

		int GetWidth() const;
		int GetHeight() const;

	private:
		int Width, Height;
	};

	// Event fired when a window gets focus.
	class WindowFocusEvent : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowFocus);

		// Engine-internal constructor. Do NOT use in client application!
		WindowFocusEvent(Window& window);
	};

	// Event fired when a window loses focus.
	class WindowUnfocusEvent : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowUnfocus);

		// Engine-internal constructor. Do NOT use in client application!
		WindowUnfocusEvent(Window& window);
	};

	// Event fired when opening a window.
	class WindowOpenEvent : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowOpen);

		// Engine-internal constructor. Do NOT use in client application!
		WindowOpenEvent(Window& window);
	};
}
