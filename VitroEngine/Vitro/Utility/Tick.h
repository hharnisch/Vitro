#pragma once

namespace Vitro
{
	struct Tick
	{
	public:
		inline Tick() = default;
		inline Tick(float milliseconds) : Time(milliseconds) {}

		inline float Seconds() const { return Time / 1000; }
		inline float Milliseconds() const { return Time; }

		inline bool operator==(Tick other) const { return Time == other.Time; }
		inline bool operator!=(Tick other) const { return Time != other.Time; }
		inline bool operator<(Tick other) const { return Time < other.Time; }
		inline bool operator>(Tick other) const { return Time > other.Time; }
		inline bool operator<=(Tick other) const { return Time <= other.Time; }
		inline bool operator>=(Tick other) const { return Time >= other.Time; }

		inline operator float() const { return Time; }
		inline explicit operator std::string() const { return std::to_string(Time); }

	private:
		float Time = 0.0f;
	};
}
