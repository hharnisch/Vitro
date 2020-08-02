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

	// Event fired when closing a window.
	class WindowCloseEvent : public WindowEvent
	{
	public:
		$EventType(WindowClose);

		// Engine-internal constructor. Do NOT use in client application!
		WindowCloseEvent(Window& window);
	};

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

	// Event fired when resizing a window.
	class WindowSizeEvent : public WindowEvent
	{
	public:
		$EventType(WindowSize);

		// Engine-internal constructor. Do NOT use in client application!
		WindowSizeEvent(Window& window, int width, int height);

		explicit operator std::string() const override;

		int GetWidth() const;
		int GetHeight() const;

	private:
		int Width;
		int Height;
	};

	// Event fired when a window gets focus.
	class WindowFocusEvent : public WindowEvent
	{
	public:
		$EventType(WindowFocus);

		// Engine-internal constructor. Do NOT use in client application!
		WindowFocusEvent(Window& window);
	};

	// Event fired when a window loses focus.
	class WindowUnfocusEvent : public WindowEvent
	{
	public:
		$EventType(WindowUnfocus);

		// Engine-internal constructor. Do NOT use in client application!
		WindowUnfocusEvent(Window& window);
	};

	// Event fired when opening a window.
	class WindowOpenEvent : public WindowEvent
	{
	public:
		$EventType(WindowOpen);

		// Engine-internal constructor. Do NOT use in client application!
		WindowOpenEvent(Window& window);
	};
}
