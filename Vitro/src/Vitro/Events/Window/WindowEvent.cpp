#include "_pch.h"
#include "WindowEvent.h"

namespace Vitro
{
	WindowEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << NativeID;
		return s.str();
	}

	uint64_t WindowEvent::GetNativeID() const
	{
		return NativeID;
	}

	WindowEvent::WindowEvent(uint64_t nativeID) : NativeID(nativeID)
	{
	}
}
