#pragma once

namespace Vitro
{
	enum class EventType : unsigned char
	{
		None			= 0,	// Never sent by an event. Only for variable initialization.
		WindowClose,
		WindowMove,
		WindowSize,
		WindowFocus,
		WindowUnfocus,
		WindowOpen,
		KeyDown,
		KeyUp,
		TextType,
		MouseMove,
		MouseDown,
		MouseUp,
		DoubleClick,
		MouseScroll
	};
}
