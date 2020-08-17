#pragma once

namespace Vitro
{
	struct TimeStep
	{
	public:
		inline TimeStep() = default;
		inline TimeStep(float milliseconds) : Time(milliseconds / 1000) {}

		inline float Seconds() const
		{
			return Time;
		}

		inline float Milliseconds() const
		{
			return Time * 1000;
		}

		inline operator float() const
		{
			return Time;
		}

	private:
		float Time = 0.0f;
	};
}
