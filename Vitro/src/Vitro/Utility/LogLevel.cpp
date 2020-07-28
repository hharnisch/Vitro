#include "_pch.h"
#include "LogLevel.h"

#define $ToString(x) case LogLevel::x: return #x

namespace Vitro
{
	std::string ToString(LogLevel level)
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
		return "Unknown log level: " + static_cast<int>(level);
	}
}
