#pragma once

#include "_pch.h"
#include "Vitro/Utility/Assert.h"

namespace Vitro
{
	// Wrapper for variable-sized arrays. All methods are memory-safe when assertions are enabled.
	template<typename T> struct Array
	{
	public:
		Array() = default;

		inline Array(size_t count) : DataCount(count)
		{
			Data = new T[count];
		}

		~Array()
		{
			delete[] Data;
		}

		Array(const Array& other) : Array(other.DataCount)
		{
			std::memcpy(Data, other.Data, DataCount * sizeof(T));
		}

		Array(Array&& other) noexcept :
			Data(std::exchange(other.Data, nullptr)),
			DataCount(other.DataCount)
		{}

		Array& operator=(const Array& other)
		{
			return *this = Array(other);
		}

		Array& operator=(Array&& other) noexcept
		{
			std::swap(Data, other.Data);
			std::swap(DataCount, other.DataCount);
			return *this;
		}

		inline T& operator[](size_t index)
		{
			Assert(index < DataCount, "Array index out of range: " + std::to_string(index));
			return *(Data + index);
		}

		inline size_t Count() const
		{
			return DataCount;
		}

		inline size_t ByteSize() const
		{
			return DataCount * sizeof(T);
		}

		__declspec(restrict) inline T* Raw()
		{
			return Data;
		}

		__declspec(restrict) inline const T* Raw() const
		{
			return Data;
		}

		class Iterator
		{
		public:
		#if VTR_ENABLE_ASSERTIONS
			Iterator(T* begin, T* position, T* end) : Begin(begin), Position(position), End(end) {}
		#else
			Iterator(T* position) : Position(position) {}
		#endif

			T& operator*()
			{
				return *Position;
			}

			bool operator==(Iterator other)
			{
				return Position == other.Position;
			}

			bool operator!=(Iterator other)
			{
				return Position != other.Position;
			}

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
		#if VTR_ENABLE_ASSERTIONS
			T* Begin;
			T* End;
		#endif
		};

		Iterator begin()
		{
		#if VTR_ENABLE_ASSERTIONS
			return Iterator(Data, Data, Data + DataCount);
		#else
			return Iterator(Data);
		#endif
		}

		Iterator end()
		{
		#if VTR_ENABLE_ASSERTIONS
			return Iterator(Data, Data + DataCount, Data + DataCount);
		#else
			return Iterator(Data + DataCount);
		#endif
		}

	private:
		T* __restrict Data = nullptr;
		size_t DataCount = 0;
	};
}
