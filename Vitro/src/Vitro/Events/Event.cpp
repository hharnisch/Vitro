#include "_pch.h"
#include "Event.h"

namespace Vitro
{
	bool Event::HasSourceFlag(EventSource flag)
	{
		return flag & GetSourceFlags();
	}

	Event::operator std::string() const
	{
		return GetName();
	}
}
