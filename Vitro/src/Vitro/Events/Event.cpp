#include "_pch.h"
#include "Event.h"

namespace Vitro
{
	Event::operator std::string() const
	{
		return GetName();
	}

	bool Event::HasSourceFlag(EventSource flag) const
	{
		return flag & GetSourceFlags();
	}

	bool Event::IsHandled() const
	{
		return Handled;
	}
}
