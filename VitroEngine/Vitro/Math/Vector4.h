﻿#pragma once

#include "Vitro/Utility/Assert.h"

#define VTR_IS_SCALAR(O) typename = typename std::enable_if_t<std::is_arithmetic_v<O>, O>

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<4, N>
	{
		union
		{
			struct { N X, Y, Z, W; };
			struct { N R, G, B, A; };
			struct { N S, T, P, Q; };
			N Val[4];
		};

		template<typename O0, typename O1, typename O2, typename O3>
		constexpr Vector(O0 x, O1 y, O2 z, O3 w) : Val{static_cast<N>(x), static_cast<N>(y),
													   static_cast<N>(z), static_cast<N>(w)}
		{}

		template<typename O>
		constexpr Vector(O scalar) :
			Vector(static_cast<N>(scalar), static_cast<N>(scalar), static_cast<N>(scalar),
				   static_cast<N>(scalar))
		{}

		template<typename O>
		constexpr Vector(const Vector<2, O>& other) : Vector(other.X, other.Y, 0, 0) {}

		template<typename O>
		constexpr Vector(const Vector<3, O>& other) : Vector(other.X, other.Y, other.Z, 0) {}

		template<typename O>
		constexpr Vector(const Vector<4, O>& other) : Vector(other.X, other.Y, other.Z, other.W) {}

		constexpr Vector() : Vector(0) {}

		inline N& operator[](size_t index)
		{
			AssertArrayRange(Val, index, "Vector");
			return Val[index];
		}

		inline const N& operator[](size_t index) const
		{
			AssertArrayRange(Val, index, "Vector");
			return Val[index];
		}

		template<typename O> inline Vector<4, N> operator+(const Vector<4, O>& v) const
		{
			return {X + v.X, Y + v.Y, Z + v.Z, W + v.W};
		}

		template<typename O> inline Vector<4, N> operator-(const Vector<4, O>& v) const
		{
			return {X - v.X, Y - v.Y, Z - v.Z, W - v.W};
		}

		template<typename O> inline Vector<4, N> operator*(const Vector<4, O>& v) const
		{
			return {X * v.X, Y * v.Y, Z * v.Z, W * v.W};
		}

		template<typename O> inline Vector<4, N> operator/(const Vector<4, O>& v) const
		{
			return {X / v.X, Y / v.Y, Z / v.Z, W / v.W};
		}

		template<typename O> inline Vector<4, N> operator%(const Vector<4, O>& v) const
		{
			return {X % v.X, Y % v.Y, Z % v.Z, W % v.W};
		}

		template<typename O> inline Vector<4, N> operator&(const Vector<4, O>& v) const
		{
			return {X & v.X, Y & v.Y, Z & v.Z, W & v.W};
		}

		template<typename O> inline Vector<4, N> operator|(const Vector<4, O>& v) const
		{
			return {X | v.X, Y | v.Y, Z | v.Z, W | v.W};
		}

		template<typename O> inline Vector<4, N> operator^(const Vector<4, O>& v) const
		{
			return {X ^ v.X, Y ^ v.Y, Z ^ v.Z, W ^ v.W};
		}

		template<typename O> inline Vector<4, N> operator<<(const Vector<4, O>& v) const
		{
			return {X << v.X, Y << v.Y, Z << v.Z, W << v.W};
		}

		template<typename O> inline Vector<4, N> operator>>(const Vector<4, O>& v) const
		{
			return {X >> v.X, Y >> v.Y, Z >> v.Z, W >> v.W};
		}

		template<typename O> inline Vector<4, N>& operator+=(const Vector<4, O>& v)
		{
			X += v.X; Y += v.Y; Z += v.Z; W += v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator-=(const Vector<4, O>& v)
		{
			X -= v.X; Y -= v.Y; Z -= v.Z; W -= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator*=(const Vector<4, O>& v)
		{
			X *= v.X; Y *= v.Y; Z *= v.Z; W *= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator/=(const Vector<4, O>& v)
		{
			X /= v.X; Y /= v.Y; Z /= v.Z; W /= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator%=(const Vector<4, O>& v)
		{
			X %= v.X; Y %= v.Y; Z %= v.Z; W %= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator&=(const Vector<4, O>& v)
		{
			X &= v.X; Y &= v.Y; Z &= v.Z; W &= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator|=(const Vector<4, O>& v)
		{
			X |= v.X; Y |= v.Y; Z |= v.Z; W |= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator^=(const Vector<4, O>& v)
		{
			X ^= v.X; Y ^= v.Y; Z ^= v.Z; W ^= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator<<=(const Vector<4, O>& v)
		{
			X <<= v.X; Y <<= v.Y; Z <<= v.Z; W <<= v.W; return *this;
		}

		template<typename O> inline Vector<4, N>& operator>>=(const Vector<4, O>& v)
		{
			X >>= v.X; Y >>= v.Y; Z >>= v.Z; W >>= v.W; return *this;
		}

		template<typename O> inline bool operator==(const Vector<4, O>& v) const
		{
			return X == v.X && Y == v.Y && Z == v.Z && W == v.W;
		}

		template<typename O> inline bool operator!=(const Vector<4, O>& v) const
		{
			return X != v.X || Y != v.Y || Z != v.Z || W != v.W;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator+(O scalar) const
		{
			return {X + scalar, Y + scalar, Z + scalar, W + scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator-(O scalar) const
		{
			return {X - scalar, Y - scalar, Z - scalar, W - scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator*(O scalar) const
		{
			return {X * scalar, Y * scalar, Z * scalar, W * scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator/(O scalar) const
		{
			return {X / scalar, Y / scalar, Z / scalar, W / scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator%(O scalar) const
		{
			return {X % scalar, Y % scalar, Z % scalar, W % scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator&(O scalar) const
		{
			return {X & scalar, Y & scalar, Z & scalar, W & scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator|(O scalar) const
		{
			return {X | scalar, Y | scalar, Z | scalar, W | scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator^(O scalar) const
		{
			return {X ^ scalar, Y ^ scalar, Z ^ scalar, W ^ scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator<<(O scalar) const
		{
			return {X << scalar, Y << scalar, Z << scalar, W << scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N> operator>>(O scalar) const
		{
			return {X >> scalar, Y >> scalar, Z >> scalar, W >> scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator+=(O scalar)
		{
			X += scalar; Y += scalar; Z += scalar; W += scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator-=(O scalar)
		{
			X -= scalar; Y -= scalar; Z -= scalar; W -= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator*=(O scalar)
		{
			X *= scalar; Y *= scalar; Z *= scalar; W *= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator/=(O scalar)
		{
			X /= scalar; Y /= scalar; Z /= scalar; W /= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator%=(O scalar)
		{
			X %= scalar; Y %= scalar; Z %= scalar; W %= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator&=(O scalar)
		{
			X &= scalar; Y &= scalar; Z &= scalar; W &= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator|=(O scalar)
		{
			X |= scalar; Y |= scalar; Z |= scalar; W |= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator^=(O scalar)
		{
			X ^= scalar; Y ^= scalar; Z ^= scalar; W ^= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator<<=(O scalar)
		{
			X <<= scalar; Y <<= scalar; Z <<= scalar; W <<= scalar; return *this;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Vector<4, N>& operator>>=(O scalar)
		{
			X >>= scalar; Y >>= scalar; Z >>= scalar; W >>= scalar; return *this;
		}

		inline Vector<4, N> operator+() const
		{
			return {+X, +Y, +Z, +W};
		}

		inline Vector<4, N> operator-() const
		{
			return {-X, -Y, -Z, -W};
		}

		inline Vector<4, N> operator~() const
		{
			return {~X, ~Y, ~Z, ~W};
		}

		inline Vector<4, N>& operator++()
		{
			++X; ++Y; ++Z; ++W; return *this;
		}

		inline Vector<4, N>& operator--()
		{
			--X; --Y; --Z; --W; return *this;
		}

		inline Vector<4, N> operator++(int)
		{
			auto oldValue = *this; ++X; ++Y; ++Z; ++W; return oldValue;
		}

		inline Vector<4, N> operator--(int)
		{
			auto oldValue = *this; --X; --Y; --Z; --W; return oldValue;
		}

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << '(' << +X << ',' << +Y << ',' << +Z << ',' << +W << ')';
			return s.str();
		}
	};

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator+(O scalar, const Vector<4, N>& v)
	{
		return {scalar + v.X, scalar + v.Y, scalar + v.Z, scalar + v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator-(O scalar, const Vector<4, N>& v)
	{
		return {scalar - v.X, scalar - v.Y, scalar - v.Z, scalar - v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator*(O scalar, const Vector<4, N>& v)
	{
		return {scalar * v.X, scalar * v.Y, scalar * v.Z, scalar * v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator/(O scalar, const Vector<4, N>& v)
	{
		return {scalar / v.X, scalar / v.Y, scalar / v.Z, scalar / v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator%(O scalar, const Vector<4, N>& v)
	{
		return {scalar % v.X, scalar % v.Y, scalar % v.Z, scalar % v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator&(O scalar, const Vector<4, N>& v)
	{
		return {scalar & v.X, scalar & v.Y, scalar & v.Z, scalar & v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator|(O scalar, const Vector<4, N>& v)
	{
		return {scalar | v.X, scalar | v.Y, scalar | v.Z, scalar | v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator^(O scalar, const Vector<4, N>& v)
	{
		return {scalar ^ v.X, scalar ^ v.Y, scalar ^ v.Z, scalar ^ v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator<<(O scalar, const Vector<4, N>& v)
	{
		return {scalar << v.X, scalar << v.Y, scalar << v.Z, scalar << v.W};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Vector<4, N> operator>>(O scalar, const Vector<4, N>& v)
	{
		return {scalar >> v.X, scalar >> v.Y, scalar >> v.Z, scalar >> v.W};
	}

	template<typename N, typename O> inline N Dot(const Vector<4, N>& lv, const Vector<4, O>& rv)
	{
		auto temp = lv * rv; return temp.X + temp.Y + temp.Z + temp.W;
	}

	template<typename N, typename O> Vector<4, O> Apply(const Vector<4, N>& v, O(*func)(N))
	{
		return {func(v.X), func(v.Y), func(v.Z), func(v.W)};
	}
}