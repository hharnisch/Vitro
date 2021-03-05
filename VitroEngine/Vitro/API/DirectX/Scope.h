#pragma once

namespace Vitro::DirectX
{
	template<typename T> class Scope final
	{
	public:
		Scope() : Pointer(nullptr)
		{}

		Scope(Scope&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr))
		{}

		~Scope()
		{
			if(Pointer)
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

		T** operator&()
		{
			return &Pointer;
		}

		T* const* operator&() const
		{
			return &Pointer;
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
