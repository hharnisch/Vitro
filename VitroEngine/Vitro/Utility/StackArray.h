#pragma once

#include "_pch.h"
#include "Vitro/Utility/Assert.h"

namespace Vitro
{
	// Wrapper for stack-allocated arrays. Will cause stack overflow if stack allocation somehow
	// fails. If too much space is tried to be allocated, it will allocate on the heap. All methods
	// are memory-safe in debug mode.
	template<typename T> class StackArray
	{
	public:
		inline StackArray(size_t count) : DataCount(count)
		{
			Data = static_cast<T*>(_malloca(count * sizeof(T)));
		}

		inline ~StackArray()
		{
			_freea(Data);
		}

		inline StackArray(const StackArray& other) : StackArray(other.DataCount)
		{
			std::memcpy(Data, other.Data, DataCount * sizeof(T));
		}

		inline StackArray& operator=(const StackArray& other)
		{
			return *this = StackArray(other);
		}

		inline T& operator[](size_t index)
		{
			Assert(index < DataCount, "Array index out of range: " + std::to_string(index));
			return *(Data + index);
		}

		inline const T& operator[](size_t index) const
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
		#if VTR_DEBUG
			inline Iterator(T* begin, T* pos, T* end) : Begin(begin), Position(pos), End(end) {}
		#else
			inline Iterator(T* position) : Position(position) {}
		#endif

			inline T& operator*()
			{
				return *Position;
			}

			inline bool operator==(Iterator other)
			{
				return Position == other.Position;
			}

			inline bool operator!=(Iterator other)
			{
				return Position != other.Position;
			}

			inline Iterator& operator++()
			{
				Assert(Position < End, "Cannot increment iterator past end.");
				Position += 1; return *this;
			}

			inline Iterator& operator--()
			{
				Assert(Begin < Position, "Cannot decrement iterator before begin.");
				Position -= 1; return *this;
			}

		private:
			T* Position;
		#if VTR_DEBUG
			T* Begin;
			T* End;
		#endif
		};

		inline Iterator begin()
		{
		#if VTR_DEBUG
			return Iterator(Data, Data, Data + DataCount);
		#else
			return Iterator(Data);
		#endif
		}

		inline Iterator end()
		{
		#if VTR_DEBUG
			return Iterator(Data, Data + DataCount, Data + DataCount);
		#else
			return Iterator(Data + DataCount);
		#endif
		}

	private:
		T* __restrict Data;
		size_t DataCount;

		StackArray(StackArray&&) = delete;
		StackArray& operator=(StackArray&&) = delete;
		void* operator new(size_t) = delete;
		void* operator new[](size_t) = delete;
		void operator delete(void*) = delete;
		void operator delete[](void*) = delete;
	};
}
