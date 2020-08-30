#pragma once

namespace Vitro
{
	struct Tick
	{
	public:
		inline Tick() = default;
		inline Tick(float seconds) : Secs(seconds) {}

		inline float Seconds() const { return Secs; }
		inline float Milliseconds() const { return Secs * 1000; }

		inline bool operator==(Tick other) const { return Secs == other.Secs; }
		inline bool operator!=(Tick other) const { return Secs != other.Secs; }
		inline bool operator<(Tick other) const { return Secs < other.Secs; }
		inline bool operator>(Tick other) const { return Secs > other.Secs; }
		inline bool operator<=(Tick other) const { return Secs <= other.Secs; }
		inline bool operator>=(Tick other) const { return Secs >= other.Secs; }

		inline operator float() const { return Secs; }
		inline explicit operator std::string() const { return std::to_string(Secs); }

	private:
		float Secs = 0.0f;
	};
}
