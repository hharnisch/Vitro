#pragma once

#include "_pch.h"
#include "Vitro/Utility/Assert.h"

namespace Vitro
{
	// Wrapper for dynamically allocated arrays. All methods are memory-safe in debug mode.
	template<typename T> class HeapArray
	{
	public:
		inline HeapArray() = default;

		inline HeapArray(size_t count) : DataCount(count)
		{
			Data = new T[count];
		}

		inline ~HeapArray()
		{
			delete[] Data;
		}

		inline HeapArray(const HeapArray& other) : HeapArray(other.DataCount)
		{
			auto src = other.begin();
			auto dst = begin();
			for(; src != other.end(); ++src, ++dst)
				*dst = *src;
		}

		inline HeapArray(HeapArray&& other) noexcept :
			Data(std::exchange(other.Data, nullptr)),
			DataCount(other.DataCount)
		{}

		inline HeapArray& operator=(const HeapArray& other)
		{
			return *this = HeapArray(other);
		}

		inline HeapArray& operator=(HeapArray&& other) noexcept
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

		class ConstIterator
		{
		public:
		#if VTR_DEBUG
			inline ConstIterator(T* begin, T* pos, T* end) : Begin(begin), Position(pos), End(end)
			{}
		#else
			inline ConstIterator(T* position) : Position(position) {}
		#endif

			inline const T& operator*() const
			{
				return *Position;
			}

			inline bool operator==(ConstIterator other) const
			{
				return Position == other.Position;
			}

			inline bool operator!=(ConstIterator other) const
			{
				return Position != other.Position;
			}

			inline ConstIterator& operator++()
			{
				Assert(Position < End, "Cannot increment iterator past end.");
				Position += 1; return *this;
			}

			inline ConstIterator& operator--()
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

		inline ConstIterator begin() const
		{
		#if VTR_DEBUG
			return ConstIterator(Data, Data, Data + DataCount);
		#else
			return ConstIterator(Data);
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

		inline ConstIterator end() const
		{
		#if VTR_DEBUG
			return ConstIterator(Data, Data + DataCount, Data + DataCount);
		#else
			return ConstIterator(Data + DataCount);
		#endif
		}

	private:
		T* __restrict Data = nullptr;
		size_t DataCount = 0;

		void* operator new(size_t) = delete;
		void operator delete(void*) = delete;
	};
}
