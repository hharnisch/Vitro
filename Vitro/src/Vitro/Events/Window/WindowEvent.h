#pragma once

#include "Vitro/Events/Event.h"

namespace Vitro
{
	// Superclass for all window events.
	class WindowEvent : public Event
	{
	public:
		$EventSource(EventSource::App);

		uint64_t GetNativeID() const;

		explicit operator std::string() const override;

	protected:
		uint64_t NativeID;

		WindowEvent(uint64_t nativeID);
	};
}
