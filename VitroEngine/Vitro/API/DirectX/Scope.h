#pragma once

#include "_pch.h"

namespace Vitro::DirectX
{
	template<typename T> class Scope final
	{
	public:
		template<typename S> class ScopeAddress final
		{
		public:
			ScopeAddress(S* scope) : Scope(scope) {}
			ScopeAddress(const S* scope) : ConstScope(scope) {}

			operator void** ()
			{
				return reinterpret_cast<void**>(&(*Scope).Pointer);
			}

			operator T** ()
			{
				return &(*Scope).Pointer;
			}

			operator T* const* () const
			{
				return &(*ConstScope).Pointer;
			}

		private:
			union
			{
				S* Scope;
				const S* ConstScope;
			};
		};

		Scope() : Pointer(nullptr) {}
		Scope(Scope&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr)) {}

		~Scope()
		{
			Pointer->Release();
		}

		Scope& operator=(Scope&& other) noexcept
		{
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

		ScopeAddress<Scope> operator&()
		{
			return this;
		}

		const ScopeAddress<Scope> operator&() const
		{
			return this;
		}

		bool operator==(Scope other) const
		{
			return Pointer == other.Pointer;
		}

		bool operator!=(Scope other) const
		{
			return Pointer != other.Pointer;
		}

		operator auto()
		{
			return Pointer;
		}

		operator auto() const
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
		T* Pointer;
	};
}
