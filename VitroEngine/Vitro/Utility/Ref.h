#pragma once

#include "_pch.h"

namespace Vitro
{
	class RefCounted
	{
	public:
		inline void IncrementRefCount() const { ++RefCount; }
		inline void DecrementRefCount() const { --RefCount; }
		inline uint32_t GetRefCount() const { return RefCount; }

	private:
		mutable uint32_t RefCount = 0;
	};

	template<typename T> class Ref final
	{
		static_assert(std::has_virtual_destructor_v<T>,
					  "Template parameter must have a virtual destructor.");

	public:
		template<typename... Args> static Ref<T> New(Args&&... args)
		{
			return Ref<T>(new T(std::forward<Args>(args)...));
		}

		Ref() : Pointer(nullptr) {}
		Ref(std::nullptr_t) : Pointer(nullptr) {}

		Ref(T* ptr) : Pointer(ptr)
		{
			static_assert(std::is_base_of_v<RefCounted, T>,
						  "Template parameter must inherit from Vitro::RefCounted.");
			IncrementRef();
		}

		Ref(const Ref& other) : Pointer(other.Pointer)
		{
			IncrementRef();
		}

		template<typename D> Ref(const Ref<D>& other) : Pointer(other.Pointer)
		{
			static_assert(std::is_base_of_v<T, D>, "Type must derive from target type.");
			IncrementRef();
		}

		Ref(Ref&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr))
		{}

		template<typename D>
		Ref(Ref<D>&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr))
		{
			static_assert(std::is_base_of_v<T, D>, "Type must derive from target type.");
		}

		~Ref()
		{
			DecrementRef();
		}

		Ref& operator=(std::nullptr_t)
		{
			DecrementRef();
			Pointer = nullptr;
			return *this;
		}

		Ref& operator=(const Ref& other)
		{
			other.IncrementRef();
			DecrementRef();
			Pointer = other.Pointer;
			return *this;
		}

		Ref& operator=(Ref&& other) noexcept
		{
			DecrementRef();
			Pointer = std::exchange(other.Pointer, nullptr);
			return *this;
		}

		T* operator->()
		{
			return Pointer;
		}

		const T* operator->() const
		{
			return Pointer;
		}

		T& operator*()
		{
			return *Pointer;
		}

		const T& operator*() const
		{
			return *Pointer;
		}

		bool operator==(const Ref& other) const
		{
			return Pointer == other.Pointer;
		}

		bool operator!=(const Ref& other) const
		{
			return Pointer != other.Pointer;
		}

		T* Raw()
		{
			return Pointer;
		}

		const T* Raw() const
		{
			return Pointer;
		}

		operator bool() const
		{
			return Pointer != nullptr;
		}

	private:
		template<class D> friend class Ref;
		T* Pointer;

		void IncrementRef() const
		{
			if(Pointer)
				Pointer->IncrementRefCount();
		}

		void DecrementRef() const
		{
			if(Pointer)
			{
				Pointer->DecrementRefCount();
				if(Pointer->GetRefCount() == 0)
					delete Pointer;
			}
		}
	};
}
