#pragma once

namespace Vitro
{
	constexpr auto Pi = 3.14159265358979L;

	template<typename N> constexpr auto Degrees(N radians)
	{
		return 180 / Pi * radians;
	}

	template<typename N> constexpr auto Radians(N degrees)
	{
		return degrees / (180 / Pi);
	}
}
