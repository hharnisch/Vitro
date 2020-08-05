#pragma once

#include "Vitro/Utility/Assert.h"

#define VTR_SCALAR typename = typename std::enable_if_t<std::is_arithmetic_v<O>, O>

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<2, N>
	{
		union
		{
			struct { N X, Y; };
			struct { N R, G; };
			struct { N S, T; };
			N Val[2];
		};

		template<typename O0, typename O1> inline Vector(O0 x, O1 y) :
			X(static_cast<N>(x)),
			Y(static_cast<N>(y))
		{}

		template<typename O> inline Vector(O scalar) :
			Vector(static_cast<N>(scalar), static_cast<N>(scalar))
		{}

		template<size_t D, typename O> inline Vector(const Vector<D, O>& other) :
			Vector(other.X, other.Y)
		{}

		inline constexpr Vector() : Vector(0) {}

		inline N& operator[](size_t index)
		{
			AssertArrayRange(Val, index, "Vector");
			return Val[index];
		}

		template<typename O> inline Vector<2, N> operator+(const Vector<2, O>& v) const
		{
			return {X + v.X, Y + v.Y};
		}

		template<typename O> inline Vector<2, N> operator-(const Vector<2, O>& v) const
		{
			return {X - v.X, Y - v.Y};
		}

		template<typename O> inline Vector<2, N> operator*(const Vector<2, O>& v) const
		{
			return {X * v.X, Y * v.Y};
		}

		template<typename O> inline Vector<2, N> operator/(const Vector<2, O>& v) const
		{
			return {X / v.X, Y / v.Y};
		}

		template<typename O> inline Vector<2, N> operator%(const Vector<2, O>& v) const
		{
			return {X % v.X, Y % v.Y};
		}

		template<typename O> inline Vector<2, N> operator&(const Vector<2, O>& v) const
		{
			return {X & v.X, Y & v.Y};
		}

		template<typename O> inline Vector<2, N> operator|(const Vector<2, O>& v) const
		{
			return {X | v.X, Y | v.Y};
		}

		template<typename O> inline Vector<2, N> operator^(const Vector<2, O>& v) const
		{
			return {X ^ v.X, Y ^ v.Y};
		}

		template<typename O> inline Vector<2, N> operator<<(const Vector<2, O>& v) const
		{
			return {X << v.X, Y << v.Y};
		}

		template<typename O> inline Vector<2, N> operator>>(const Vector<2, O>& v) const
		{
			return {X >> v.X, Y >> v.Y};
		}

		template<typename O> inline Vector<2, N>& operator+=(const Vector<2, O>& v)
		{
			X += v.X; Y += v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator-=(const Vector<2, O>& v)
		{
			X -= v.X; Y -= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator*=(const Vector<2, O>& v)
		{
			X *= v.X; Y *= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator/=(const Vector<2, O>& v)
		{
			X /= v.X; Y /= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator%=(const Vector<2, O>& v)
		{
			X %= v.X; Y %= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator&=(const Vector<2, O>& v)
		{
			X &= v.X; Y &= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator|=(const Vector<2, O>& v)
		{
			X |= v.X; Y |= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator^=(const Vector<2, O>& v)
		{
			X ^= v.X; Y ^= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator<<=(const Vector<2, O>& v)
		{
			X <<= v.X; Y <<= v.Y; return *this;
		}

		template<typename O> inline Vector<2, N>& operator>>=(const Vector<2, O>& v)
		{
			X >>= v.X; Y >>= v.Y; return *this;
		}

		template<typename O> inline bool operator==(const Vector<2, O>& v) const
		{
			return X == v.X && Y == v.Y;
		}

		template<typename O> inline bool operator!=(const Vector<2, O>& v) const
		{
			return X != v.X || Y != v.Y;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator+(O scalar) const
		{
			return {X + scalar, Y + scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator-(O scalar) const
		{
			return {X - scalar, Y - scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator*(O scalar) const
		{
			return {X * scalar, Y * scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator/(O scalar) const
		{
			return {X / scalar, Y / scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator%(O scalar) const
		{
			return {X % scalar, Y % scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator&(O scalar) const
		{
			return {X & scalar, Y & scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator|(O scalar) const
		{
			return {X | scalar, Y | scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator^(O scalar) const
		{
			return {X ^ scalar, Y ^ scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator<<(O scalar) const
		{
			return {X << scalar, Y << scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N> operator>>(O scalar) const
		{
			return {X >> scalar, Y >> scalar};
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator+=(O scalar)
		{
			X += scalar; Y += scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator-=(O scalar)
		{
			X -= scalar; Y -= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator*=(O scalar)
		{
			X *= scalar; Y *= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator/=(O scalar)
		{
			X /= scalar; Y /= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator%=(O scalar)
		{
			X %= scalar; Y %= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator&=(O scalar)
		{
			X &= scalar; Y &= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator|=(O scalar)
		{
			X |= scalar; Y |= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator^=(O scalar)
		{
			X ^= scalar; Y ^= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator<<=(O scalar)
		{
			X <<= scalar; Y <<= scalar; return *this;
		}

		template<typename O, VTR_SCALAR> inline Vector<2, N>& operator>>=(O scalar)
		{
			X >>= scalar; Y >>= scalar; return *this;
		}

		inline Vector<2, N> operator+() const
		{
			return {+X, +Y};
		}

		inline Vector<2, N> operator-() const
		{
			return {-X, -Y};
		}

		inline Vector<2, N> operator~() const
		{
			return {~X, ~Y};
		}

		inline Vector<2, N>& operator++()
		{
			++X; ++Y; return *this;
		}

		inline Vector<2, N>& operator--()
		{
			--X; --Y; return *this;
		}

		inline Vector<2, N> operator++(int)
		{
			auto oldValue = *this; ++X; ++Y; return oldValue;
		}

		inline Vector<2, N> operator--(int)
		{
			auto oldValue = *this; --X; --Y; return oldValue;
		}

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << "(" << +X << "," << +Y << ")";
			return s.str();
		}
	};

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator+(O scalar, const Vector<2, N>& v)
	{
		return {scalar + v.X, scalar + v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator-(O scalar, const Vector<2, N>& v)
	{
		return {scalar - v.X, scalar - v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator*(O scalar, const Vector<2, N>& v)
	{
		return {scalar * v.X, scalar * v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator/(O scalar, const Vector<2, N>& v)
	{
		return {scalar / v.X, scalar / v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator%(O scalar, const Vector<2, N>& v)
	{
		return {scalar % v.X, scalar % v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator&(O scalar, const Vector<2, N>& v)
	{
		return {scalar & v.X, scalar & v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator|(O scalar, const Vector<2, N>& v)
	{
		return {scalar | v.X, scalar | v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator^(O scalar, const Vector<2, N>& v)
	{
		return {scalar ^ v.X, scalar ^ v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator<<(O scalar, const Vector<2, N>& v)
	{
		return {scalar << v.X, scalar << v.Y};
	}

	template<typename N, typename O, VTR_SCALAR>
	inline Vector<2, N> operator>>(O scalar, const Vector<2, N>& v)
	{
		return {scalar >> v.X, scalar >> v.Y};
	}

	template<typename N, typename O> inline N Dot(const Vector<2, N>& lv, const Vector<2, O>& rv)
	{
		auto temp = lv * rv; return temp.X + temp.Y;
	}

	template<typename N, typename O> Vector<2, O> Apply(const Vector<2, N>& v, O(*func)(N))
	{
		return {func(v.X), func(v.Y)};
	}
}
