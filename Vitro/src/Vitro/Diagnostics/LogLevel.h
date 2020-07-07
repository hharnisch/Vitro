#pragma once

namespace Vitro
{
	enum class LogLevel : uint8_t
	{
		Trace	= 0x0B,	// Renders with cyan text.
		Debug	= 0x0A,	// Renders with green text.
		Info	= 0x0F,	// Renders with white text.
		Warn	= 0x0E,	// Renders with yellow text.
		Error	= 0x0C,	// Renders with red text.
		Fatal	= 0x4F	// Renders with white text and a dark red background.
	};
}
