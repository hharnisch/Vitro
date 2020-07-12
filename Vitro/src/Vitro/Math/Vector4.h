#pragma once

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<4, N>
	{
		union { N X, R, S; };
		union { N Y, G, T; };
		union { N Z, B, P; };
		union { N W, A, Q; };

		inline Vector() = default;
		inline Vector(N x, N y, N z, N w) : X(x), Y(y), Z(z), W(w) {}
		inline Vector(N scalar) : X(scalar), Y(scalar), Z(scalar), W(scalar) {}

		template<typename O1, typename O2, typename O3, typename O4>
		inline Vector(O1 x, O2 y, O3 z, O4 w)
			: X(static_cast<N>(x)), Y(static_cast<N>(y)), Z(static_cast<N>(z)), W(static_cast<N>(w))
		{}

		template<typename O>
		inline Vector(O scalar) : X(static_cast<N>(scalar)), Y(static_cast<N>(scalar)),
			Z(static_cast<N>(scalar)), W(static_cast<N>(scalar))
		{}

		template<typename O>
		inline Vector(const Vector<4, O>& other) : X(other.X), Y(other.Y), Z(other.Z), W(other.W) {}

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

	template<typename N> inline N Dot(const Vector<4, N>& v1, const Vector<4, N>& v2)
	{
		auto temp = v1 * v2; return temp.X + temp.Y + temp.Z + temp.W;
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
