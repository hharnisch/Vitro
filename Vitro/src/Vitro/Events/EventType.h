#pragma once

namespace Vitro
{
	enum class EventType : uint8_t
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
		WindowClose,
		WindowSize,
		WindowFocus,
		WindowUnfocus,
		WindowMove
	};
}
