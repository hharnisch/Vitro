#pragma once

#include "_pch.h"

namespace Vitro
{
	template<typename T> class Scope final
	{
		static_assert(std::has_virtual_destructor_v<T>,
					  "Template parameter must have a virtual destructor.");

	public:
		template<typename... Args> static Scope New(Args&&... args)
		{
			return Scope(new T(std::forward<Args>(args)...));
		}

		Scope() : Pointer(nullptr) {}
		Scope(std::nullptr_t) : Pointer(nullptr) {}
		Scope(T* ptr) : Pointer(ptr) {}
		Scope(Scope&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr)) {}

		template<typename D>
		Scope(Scope<D>&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr))
		{
			static_assert(std::is_base_of_v<T, D>, "Type must derive from target type.");
		}

		~Scope()
		{
			delete Pointer;
		}

		Scope& operator=(Scope&& other) noexcept
		{
			std::swap(Pointer, other.Pointer);
			return *this;
		}

		template<typename D> Scope& operator=(Scope<D>&& other)
		{
			static_assert(std::is_base_of_v<T, D>, "Type must derive from target type.");
			std::swap(Pointer, other.Pointer);
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

		Scope(const Scope&) = delete;
		Scope& operator=(const Scope&) = delete;

	private:
		template<class D> friend class Scope;

		T* Pointer;
	};
}
