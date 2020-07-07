#include "_pch.h"
#include "WindowEvent.h"

namespace Vitro
{
	uint64_t WindowEvent::GetNativeID() const
	{
		return NativeID;
	}

	WindowEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << NativeID;
		return s.str();
	}

	WindowEvent::WindowEvent(uint64_t nativeID) : NativeID(nativeID)
	{
	}
}
