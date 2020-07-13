#pragma once

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
		};

		inline Vector() = default;

		template<typename O0, typename O1, typename O2, typename O3>
		inline Vector(O0 x, O1 y, O2 z, O3 w) : X(static_cast<N>(x)), Y(static_cast<N>(y)),
			Z(static_cast<N>(z)), W(static_cast<N>(w))
		{}

		template<typename O>
		inline Vector(O scalar) : Vector(static_cast<N>(scalar), static_cast<N>(scalar),
										 static_cast<N>(scalar), static_cast<N>(scalar))
		{}

		template<typename O>
		inline Vector(const Vector<4, O>& other) : Vector(other.X, other.Y, other.Z, other.W) {}

		inline N& operator[](size_t index)
		{
			switch(index)
			{
				case 0: return X;
				case 1: return Y;
				case 2: return Z;
				case 3: return W;
				default: throw std::out_of_range("Vector index out of range.");
			}
		}

		inline Vector<4, N> operator+(const Vector<4, N>& vector) const
		{
			return {X + vector.X, Y + vector.Y, Z + vector.Z, W + vector.W};
		}

		inline Vector<4, N> operator-(const Vector<4, N>& vector) const
		{
			return {X - vector.X, Y - vector.Y, Z - vector.Z, W - vector.W};
		}

		inline Vector<4, N> operator*(const Vector<4, N>& vector) const
		{
			return {X * vector.X, Y * vector.Y, Z * vector.Z, W * vector.W};
		}

		inline Vector<4, N> operator/(const Vector<4, N>& vector) const
		{
			return {X / vector.X, Y / vector.Y, Z / vector.Z, W / vector.W};
		}

		inline Vector<4, N> operator%(const Vector<4, N>& vector) const
		{
			return {X % vector.X, Y % vector.Y, Z % vector.Z, W % vector.W};
		}

		inline Vector<4, N> operator&(const Vector<4, N>& vector) const
		{
			return {X & vector.X, Y & vector.Y, Z & vector.Z, W & vector.W};
		}

		inline Vector<4, N> operator|(const Vector<4, N>& vector) const
		{
			return {X | vector.X, Y | vector.Y, Z | vector.Z, W | vector.W};
		}

		inline Vector<4, N> operator^(const Vector<4, N>& vector) const
		{
			return {X ^ vector.X, Y ^ vector.Y, Z ^ vector.Z, W ^ vector.W};
		}

		inline Vector<4, N> operator<<(const Vector<4, N>& vector) const
		{
			return {X << vector.X, Y << vector.Y, Z << vector.Z, W << vector.W};
		}

		inline Vector<4, N> operator>>(const Vector<4, N>& vector) const
		{
			return {X >> vector.X, Y >> vector.Y, Z >> vector.Z, W >> vector.W};
		}

		inline Vector<4, N>& operator+=(const Vector<4, N>& vector)
		{
			X += vector.X; Y += vector.Y; Z += vector.Z; W += vector.W; return *this;
		}

		inline Vector<4, N>& operator-=(const Vector<4, N>& vector)
		{
			X -= vector.X; Y -= vector.Y; Z -= vector.Z; W -= vector.W; return *this;
		}

		inline Vector<4, N>& operator*=(const Vector<4, N>& vector)
		{
			X *= vector.X; Y *= vector.Y; Z *= vector.Z; W *= vector.W; return *this;
		}

		inline Vector<4, N>& operator/=(const Vector<4, N>& vector)
		{
			X /= vector.X; Y /= vector.Y; Z /= vector.Z; W /= vector.W; return *this;
		}

		inline Vector<4, N>& operator%=(const Vector<4, N>& vector)
		{
			X %= vector.X; Y %= vector.Y; Z %= vector.Z; W %= vector.W; return *this;
		}

		inline Vector<4, N>& operator&=(const Vector<4, N>& vector)
		{
			X &= vector.X; Y &= vector.Y; Z &= vector.Z; W &= vector.W; return *this;
		}

		inline Vector<4, N>& operator|=(const Vector<4, N>& vector)
		{
			X |= vector.X; Y |= vector.Y; Z |= vector.Z; W |= vector.W; return *this;
		}

		inline Vector<4, N>& operator^=(const Vector<4, N>& vector)
		{
			X ^= vector.X; Y ^= vector.Y; Z ^= vector.Z; W ^= vector.W; return *this;
		}

		inline Vector<4, N>& operator<<=(const Vector<4, N>& vector)
		{
			X <<= vector.X; Y <<= vector.Y; Z <<= vector.Z; W <<= vector.W; return *this;
		}

		inline Vector<4, N>& operator>>=(const Vector<4, N>& vector)
		{
			X >>= vector.X; Y >>= vector.Y; Z >>= vector.Z; W >>= vector.W; return *this;
		}

		inline bool operator==(const Vector<4, N>& vector) const
		{
			return X == vector.X && Y == vector.Y && Z == vector.Z && W == vector.W;
		}

		inline bool operator!=(const Vector<4, N>& vector) const
		{
			return X != vector.X || Y != vector.Y || Z != vector.Z || W != vector.W;
		}

		inline Vector<4, N> operator+(N scalar) const
		{
			return {X + scalar, Y + scalar, Z + scalar, W + scalar};
		}

		inline Vector<4, N> operator-(N scalar) const
		{
			return {X - scalar, Y - scalar, Z - scalar, W - scalar};
		}

		inline Vector<4, N> operator*(N scalar) const
		{
			return {X * scalar, Y * scalar, Z * scalar, W * scalar};
		}

		inline Vector<4, N> operator/(N scalar) const
		{
			return {X / scalar, Y / scalar, Z / scalar, W / scalar};
		}

		inline Vector<4, N> operator%(N scalar) const
		{
			return {X % scalar, Y % scalar, Z % scalar, W % scalar};
		}

		inline Vector<4, N> operator&(N scalar) const
		{
			return {X & scalar, Y & scalar, Z & scalar, W & scalar};
		}

		inline Vector<4, N> operator|(N scalar) const
		{
			return {X | scalar, Y | scalar, Z | scalar, W | scalar};
		}

		inline Vector<4, N> operator^(N scalar) const
		{
			return {X ^ scalar, Y ^ scalar, Z ^ scalar, W ^ scalar};
		}

		inline Vector<4, N> operator<<(N scalar) const
		{
			return {X << scalar, Y << scalar, Z << scalar, W << scalar};
		}

		inline Vector<4, N> operator>>(N scalar) const
		{
			return {X >> scalar, Y >> scalar, Z >> scalar, W >> scalar};
		}

		inline Vector<4, N>& operator+=(N scalar)
		{
			X += scalar; Y += scalar; Z += scalar; W += scalar; return *this;
		}

		inline Vector<4, N>& operator-=(N scalar)
		{
			X -= scalar; Y -= scalar; Z -= scalar; W -= scalar; return *this;
		}

		inline Vector<4, N>& operator*=(N scalar)
		{
			X *= scalar; Y *= scalar; Z *= scalar; W *= scalar; return *this;
		}

		inline Vector<4, N>& operator/=(N scalar)
		{
			X /= scalar; Y /= scalar; Z /= scalar; W /= scalar; return *this;
		}

		inline Vector<4, N>& operator%=(N scalar)
		{
			X %= scalar; Y %= scalar; Z %= scalar; W %= scalar; return *this;
		}

		inline Vector<4, N>& operator&=(N scalar)
		{
			X &= scalar; Y &= scalar; Z &= scalar; W &= scalar; return *this;
		}

		inline Vector<4, N>& operator|=(N scalar)
		{
			X |= scalar; Y |= scalar; Z |= scalar; W |= scalar; return *this;
		}

		inline Vector<4, N>& operator^=(N scalar)
		{
			X ^= scalar; Y ^= scalar; Z ^= scalar; W ^= scalar; return *this;
		}

		inline Vector<4, N>& operator<<=(N scalar)
		{
			X <<= scalar; Y <<= scalar; Z <<= scalar; W <<= scalar; return *this;
		}

		inline Vector<4, N>& operator>>=(N scalar)
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
			s << "(" << X << ", " << Y << ", " << Z << ", " << W << ")";
			return s.str();
		}
	};

	template<typename N> inline N Dot(const Vector<4, N>& lv, const Vector<4, N>& rv)
	{
		auto temp = lv * rv; return temp.X + temp.Y + temp.Z + temp.W;
	}

	template<typename N> inline Vector<4, N> operator+(N scalar, const Vector<4, N>& vector)
	{
		return {scalar + vector.X, scalar + vector.Y, scalar + vector.Z, scalar + vector.W};
	}

	template<typename N> inline Vector<4, N> operator-(N scalar, const Vector<4, N>& vector)
	{
		return {scalar - vector.X, scalar - vector.Y, scalar - vector.Z, scalar - vector.W};
	}

	template<typename N> inline Vector<4, N> operator*(N scalar, const Vector<4, N>& vector)
	{
		return {scalar * vector.X, scalar * vector.Y, scalar * vector.Z, scalar * vector.W};
	}

	template<typename N> inline Vector<4, N> operator/(N scalar, const Vector<4, N>& vector)
	{
		return {scalar / vector.X, scalar / vector.Y, scalar / vector.Z, scalar / vector.W};
	}

	template<typename N> inline Vector<4, N> operator%(N scalar, const Vector<4, N>& vector)
	{
		return {scalar % vector.X, scalar % vector.Y, scalar % vector.Z, scalar % vector.W};
	}

	template<typename N> inline Vector<4, N> operator&(N scalar, const Vector<4, N>& vector)
	{
		return {scalar & vector.X, scalar & vector.Y, scalar & vector.Z, scalar & vector.W};
	}

	template<typename N> inline Vector<4, N> operator|(N scalar, const Vector<4, N>& vector)
	{
		return {scalar | vector.X, scalar | vector.Y, scalar | vector.Z, scalar | vector.W};
	}

	template<typename N> inline Vector<4, N> operator^(N scalar, const Vector<4, N>& vector)
	{
		return {scalar ^ vector.X, scalar ^ vector.Y, scalar ^ vector.Z, scalar ^ vector.W};
	}

	template<typename N> inline Vector<4, N> operator<<(N scalar, const Vector<4, N>& vector)
	{
		return {scalar << vector.X, scalar << vector.Y, scalar << vector.Z, scalar << vector.W};
	}

	template<typename N> inline Vector<4, N> operator>>(N scalar, const Vector<4, N>& vector)
	{
		return {scalar >> vector.X, scalar >> vector.Y, scalar >> vector.Z, scalar >> vector.W};
	}

	template<typename N, typename O> Vector<4, O> Apply(const Vector<4, N>& vector, O(*func)(N))
	{
		return {func(vector.X), func(vector.Y), func(vector.Z), func(vector.W)};
	}
}
