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

		inline explicit operator std::string() const override
		{
			std::stringstream s;
			s << GetName() << ": " << &WindowRef;
			return s.str();
		}

		inline Window& GetWindow()
		{
			return WindowRef;
		}

	protected:
		Window& WindowRef;

		inline WindowEvent(Window& window) : WindowRef(window) {}
	};

	// Event fired when closing a window.
	class WindowCloseEvent final : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowClose);

		// Engine-internal constructor. Do NOT use in client application!
		inline WindowCloseEvent(Window& window) : WindowEvent(window) {}
	};

	// Event fired when resizing a window.
	class WindowMoveEvent final : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowMove);

		// Engine-internal constructor. Do NOT use in client application!
		inline WindowMoveEvent(Window& window, int x, int y) : WindowEvent(window), X(x), Y(y) {}

		inline explicit operator std::string() const override
		{
			std::stringstream s;
			s << GetName() << ": " << &WindowRef << ", " << X << ", " << Y;
			return s.str();
		}

		inline int GetX() const
		{
			return X;
		}

		inline int GetY() const
		{
			return Y;
		}

	private:
		int X, Y;
	};

	// Event fired when resizing a window.
	class WindowSizeEvent final : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowSize);

		// Engine-internal constructor. Do NOT use in client application!
		inline WindowSizeEvent(Window& window, int width, int height) :
			WindowEvent(window), Width(width), Height(height)
		{}

		inline explicit operator std::string() const override
		{
			std::stringstream s;
			s << GetName() << ": " << &WindowRef << ", " << Width << ", " << Height;
			return s.str();
		}

		inline int GetWidth() const
		{
			return Width;
		}

		inline int GetHeight() const
		{
			return Height;
		}

	private:
		int Width, Height;
	};

	// Event fired when a window gets focus.
	class WindowFocusEvent final : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowFocus);

		// Engine-internal constructor. Do NOT use in client application!
		inline WindowFocusEvent(Window& window) : WindowEvent(window) {}
	};

	// Event fired when a window loses focus.
	class WindowUnfocusEvent final : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowUnfocus);

		// Engine-internal constructor. Do NOT use in client application!
		inline WindowUnfocusEvent(Window& window) : WindowEvent(window) {}
	};

	// Event fired when opening a window.
	class WindowOpenEvent final : public WindowEvent
	{
	public:
		VTR_EVENT_TYPE(WindowOpen);

		// Engine-internal constructor. Do NOT use in client application!
		inline WindowOpenEvent(Window& window) : WindowEvent(window) {}
	};
}
