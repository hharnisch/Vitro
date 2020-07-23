#include "_pch.h"
#include "LogLevel.h"

#include "Vitro/Diagnostics/Assert.h"

#define $ToString(x) case LogLevel::x: return os << #x

namespace Vitro
{
	std::ostream& operator<<(std::ostream& os, LogLevel level)
	{
		switch(level)
		{
			$ToString(Trace);
			$ToString(Debug);
			$ToString(Info);
			$ToString(Warn);
			$ToString(Error);
			$ToString(Fatal);
		}
		return os << "Unknown log level: " << static_cast<int>(level);
	}
}
