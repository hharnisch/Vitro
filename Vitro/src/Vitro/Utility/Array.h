#pragma once

#include "Vitro/Utility/Assert.h"

namespace Vitro
{
	// Wrapper for variable-sized arrays. All methods are memory-safe when assertions are enabled.
	template<typename T> struct Array
	{
	public:
		T* Data;

		Array(size_t count) : DataCount(count) { Data = new T[count]; }
		~Array() { delete[] Data; }

		T& operator[](size_t index)
		{
			Assert(index < DataCount, "Array index out of range: " + std::to_string(index));
			return *(Data + index);
		}

		size_t Count() const { return DataCount; }

		class Iterator
		{
		public:
		#if $ENABLE_ASSERTIONS
			Iterator(T* begin, T* position, T* end) : Begin(begin), Position(position), End(end) {}
		#else
			Iterator(T* position) : Position(position) {}
		#endif

			T& operator*() { return *Position; }
			bool operator==(Iterator other) { return Position == other.Position; }
			bool operator!=(Iterator other) { return Position != other.Position; }

			Iterator& operator++()
			{
				Assert(Position < End, "Cannot increment iterator past end.");
				Position += 1; return *this;
			}

			Iterator& operator--()
			{
				Assert(Begin < Position, "Cannot decrement iterator before begin.");
				Position -= 1; return *this;
			}

		private:
			T* Position;
		#if $ENABLE_ASSERTIONS
			T* Begin;
			T* End;
		#endif
		};

		Iterator begin()
		{
		#if $ENABLE_ASSERTIONS
			return Iterator(Data, Data, Data + DataCount);
		#else
			return Iterator(Data);
		#endif
		}

		Iterator end()
		{
		#if $ENABLE_ASSERTIONS
			return Iterator(Data, Data + DataCount, Data + DataCount);
		#else
			return Iterator(Data + DataCount);
		#endif
		}

	private:
		size_t DataCount;
	};
}
