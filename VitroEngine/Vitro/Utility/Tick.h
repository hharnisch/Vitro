#pragma once

namespace Vitro
{
	struct Tick
	{
	public:
		inline static uint64_t MeasureTime()
		{
			using namespace std::chrono;
			auto now = steady_clock::now().time_since_epoch();
			return duration_cast<microseconds>(now).count();
		}

		inline Tick() = default;

		inline Tick(uint64_t previousTime, uint64_t currentTime)
		{
			Secs = (currentTime - previousTime) / 1000000.f;
		}

		inline float Seconds() const { return Secs; }
		inline float Milliseconds() const { return Secs * 1000; }

		inline bool operator==(Tick other) const { return Secs == other.Secs; }
		inline bool operator!=(Tick other) const { return Secs != other.Secs; }
		inline bool operator<(Tick other) const { return Secs < other.Secs; }
		inline bool operator>(Tick other) const { return Secs > other.Secs; }
		inline bool operator<=(Tick other) const { return Secs <= other.Secs; }
		inline bool operator>=(Tick other) const { return Secs >= other.Secs; }

		inline std::string ToString() const
		{
			float ms = Milliseconds();
			int length = _scprintf("%4.3f", ms);
			std::string str(length, '\0');
			sprintf_s(&str[0], length + 1, "%4.3f", ms);
			return str + " ms";
		}

		inline operator float() const { return Secs; }

	private:
		float Secs = 0.0f;
	};
}
