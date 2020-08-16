#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Events/MouseCode.h"

namespace Vitro
{
	// Superclass for all mouse events.
	class MouseEvent : public Event
	{
	public:
		VTR_EVENT_SOURCE(EventSource::Input | EventSource::MouseButton);

		inline explicit operator std::string() const override
		{
			std::stringstream s;
			s << GetName() << ": " << ToString(Button);
			return s.str();
		}

		inline MouseCode GetButton() const
		{
			return Button;
		}

	protected:
		MouseCode Button;

		inline MouseEvent(MouseCode button) : Button(button) {}
	};

	// Event fired when moving the mouse.
	class MouseMoveEvent : public MouseEvent
	{
	public:
		VTR_EVENT_SOURCE(EventSource::Input | EventSource::Mouse);
		VTR_EVENT_TYPE(MouseMove);

		// Engine-internal constructor. Do NOT use in client application!
		inline MouseMoveEvent(int x, int y) : MouseEvent(MouseCode::None), X(x), Y(y) {}

		inline explicit operator std::string() const override
		{
			std::stringstream s;
			s << GetName() << ": " << X << ", " << Y;
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

	// Event fired when pressing down a mouse button.
	class MouseDownEvent : public MouseEvent
	{
	public:
		VTR_EVENT_TYPE(MouseDown);

		// Engine-internal constructor. Do NOT use in client application!
		inline MouseDownEvent(MouseCode button) : MouseEvent(button) {}
	};

	// Event fired when releasing a mouse button.
	class MouseUpEvent : public MouseEvent
	{
	public:
		VTR_EVENT_TYPE(MouseUp);

		// Engine-internal constructor. Do NOT use in client application!
		inline MouseUpEvent(MouseCode button) : MouseEvent(button) {}
	};

	// Event fired when double-clicking a mouse button.
	class DoubleClickEvent : public MouseEvent
	{
	public:
		VTR_EVENT_TYPE(DoubleClick);

		// Engine-internal constructor. Do NOT use in client application!
		inline DoubleClickEvent(MouseCode button) : MouseEvent(button) {}
	};

	// Event fired when scrolling the mouse wheel.
	class MouseScrollEvent : public MouseEvent
	{
	public:
		VTR_EVENT_SOURCE(EventSource::Input | EventSource::Mouse);
		VTR_EVENT_TYPE(MouseScroll);

		// Engine-internal constructor. Do NOT use in client application!
		inline MouseScrollEvent(float xOffset, float yOffset) :
			MouseEvent(MouseCode::Wheel), XOffset(xOffset), YOffset(yOffset)
		{}

		inline explicit operator std::string() const override
		{
			std::stringstream s;
			s << GetName() << ": " << XOffset << ", " << YOffset;
			return s.str();
		}

		// The fraction of the detent that was scrolled sideways.
		inline float GetXOffset() const
		{
			return XOffset;
		}

		// The fraction of the detent that was scrolled upwards.
		inline float GetYOffset() const
		{
			return YOffset;
		}

	private:
		float XOffset, YOffset;
	};
}