#pragma once

#include "_pch.h"

#define ArrayCount(arr) (sizeof(arr) / sizeof(*arr))

#if VTR_DEBUG

#define Assert(condition, message) if(!(condition)) __debugbreak();

#define AssertCritical(condition, message) Assert(condition, message)

#define AssertArrayRange(arr, index, arrayName)						\
	if(index >= sizeof(arr) / sizeof(*arr))							\
		throw std::out_of_range(std::string(arrayName) + " index out of range.");

#else

#define Assert(condition, message)

#define AssertCritical(condition, message)		\
		if(!(condition))						\
			throw std::runtime_error(message);

#define AssertArrayRange(arr, index, arrayName)

#endif
