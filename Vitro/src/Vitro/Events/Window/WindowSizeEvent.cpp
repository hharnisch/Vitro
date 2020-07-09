#include "_pch.h"
#include "WindowSizeEvent.h"

namespace Vitro
{
	WindowSizeEvent::WindowSizeEvent(uint64_t nativeID, int width, int height)
		: WindowEvent(nativeID), Width(width), Height(height)
	{
	}

	WindowSizeEvent::operator std::string() const
	{
		std::stringstream s;
		s << GetName() << ": " << NativeID << ", " << Width << ", " << Height;
		return s.str();
	}

	int WindowSizeEvent::GetWidth() const
	{
		return Width;
	}

	int WindowSizeEvent::GetHeight() const
	{
		return Height;
	}
}
