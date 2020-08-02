#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/MouseCode.h"

namespace Vitro
{
	// Superclass for all mouse events.
	class MouseEvent : public Event
	{
	public:
		$EventSource(EventSource::Input | EventSource::MouseButton);

		explicit operator std::string() const override;

		MouseCode GetButton() const;

	protected:
		MouseCode Button;

		MouseEvent(MouseCode button);
	};

	// Event fired when moving the mouse.
	class MouseMoveEvent : public MouseEvent
	{
	public:
		$EventSource(EventSource::Input | EventSource::Mouse);
		$EventType(MouseMove);

		// Engine-internal constructor. Do NOT use in client application!
		MouseMoveEvent(int x, int y);

		explicit operator std::string() const override;

		int GetX() const;
		int GetY() const;

	private:
		int X;
		int Y;
	};

	// Event fired when pressing down a mouse button.
	class MouseDownEvent : public MouseEvent
	{
	public:
		$EventType(MouseDown);

		// Engine-internal constructor. Do NOT use in client application!
		MouseDownEvent(MouseCode button);
	};

	// Event fired when releasing a mouse button.
	class MouseUpEvent : public MouseEvent
	{
	public:
		$EventType(MouseUp);

		// Engine-internal constructor. Do NOT use in client application!
		MouseUpEvent(MouseCode button);
	};

	// Event fired when double-clicking a mouse button.
	class DoubleClickEvent : public MouseEvent
	{
	public:
		$EventType(DoubleClick);

		// Engine-internal constructor. Do NOT use in client application!
		DoubleClickEvent(MouseCode button);
	};

	// Event fired when scrolling the mouse wheel.
	class MouseScrollEvent : public MouseEvent
	{
	public:
		$EventSource(EventSource::Input | EventSource::Mouse);
		$EventType(MouseScroll);

		// Engine-internal constructor. Do NOT use in client application!
		MouseScrollEvent(float xOffset, float yOffset);

		explicit operator std::string() const override;

		// The fraction of the detent that was scrolled sideways.
		float GetXOffset() const;

		// The fraction of the detent that was scrolled upwards.
		float GetYOffset() const;

	private:
		float XOffset;
		float YOffset;
	};
}
