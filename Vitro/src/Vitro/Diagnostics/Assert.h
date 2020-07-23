#pragma once

namespace Vitro
{
#define Assert(condition, message)			\
	if(!(condition))						\
		throw std::runtime_error(message);

#define AssertArrayRange(arr, index, arrayName)						\
	if(index >= sizeof(arr) / sizeof(*arr))							\
		throw std::out_of_range(arrayName + " index out of range.");
}
