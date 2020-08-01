#pragma once

namespace Vitro
{
	enum class EventType : unsigned char
	{
		None			= 0,	// Never sent by an event. Only for variable initialization.
		KeyDown,
		KeyUp,
		TextType,
		MouseMove,
		MouseScroll,
		MouseDown,
		MouseUp,
		DoubleClick,
		WindowOpen,
		WindowClose,
		WindowFocus,
		WindowUnfocus,
		WindowSize,
		WindowMove
	};
}
