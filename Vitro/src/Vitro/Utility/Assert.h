#pragma once

#if VTR_ENABLE_ASSERTIONS

#define Assert(condition, message)			\
	if(!(condition))						\
		throw std::runtime_error(message);

#define AssertArrayRange(arr, index, arrayName)						\
	if(index >= sizeof(arr) / sizeof(*arr))							\
		throw std::out_of_range(arrayName + " index out of range.");

#else

#define Assert(condition, message)
#define AssertArrayRange(arr, index, arrayName)

#endif
