#pragma once

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<3, N>
	{
		union { N X, R, S; };
		union { N Y, G, T; };
		union { N Z, B, P; };

		inline Vector() = default;
		inline Vector(N x, N y, N z) : X(x), Y(y), Z(z) {}
		inline Vector(N scalar) : X(scalar), Y(scalar), Z(scalar) {}

		template<typename O1, typename O2, typename O3>
		inline Vector(O1 x, O2 y, O3 z)
			: X(static_cast<N>(x)), Y(static_cast<N>(y)), Z(static_cast<N>(z))
		{}

		template<typename O>
		inline Vector(O scalar) : X(static_cast<N>(scalar)), Y(static_cast<N>(scalar)),
			Z(static_cast<N>(scalar))
		{}

		template<typename O>
		inline Vector(const Vector<3, O>& other) : X(other.X), Y(other.Y), Z(other.Z) {}

		inline N& operator[](size_t index)
		{
			switch(index)
			{
				case 0: return X;
				case 1: return Y;
				case 2: return Z;
				default: throw std::out_of_range("Vector index out of range.");
			}
		}

		inline Vector<3, N> operator+(const Vector<3, N>& vector) const
		{
			return {X + vector.X, Y + vector.Y, Z + vector.Z};
		}

		inline Vector<3, N> operator-(const Vector<3, N>& vector) const
		{
			return {X - vector.X, Y - vector.Y, Z - vector.Z};
		}

		inline Vector<3, N> operator*(const Vector<3, N>& vector) const
		{
			return {X * vector.X, Y * vector.Y, Z * vector.Z};
		}

		inline Vector<3, N> operator/(const Vector<3, N>& vector) const
		{
			return {X / vector.X, Y / vector.Y, Z / vector.Z};
		}

		inline Vector<3, N> operator%(const Vector<3, N>& vector) const
		{
			return {X % vector.X, Y % vector.Y, Z % vector.Z};
		}

		inline Vector<3, N> operator&(const Vector<3, N>& vector) const
		{
			return {X & vector.X, Y & vector.Y, Z & vector.Z};
		}

		inline Vector<3, N> operator|(const Vector<3, N>& vector) const
		{
			return {X | vector.X, Y | vector.Y, Z | vector.Z};
		}

		inline Vector<3, N> operator^(const Vector<3, N>& vector) const
		{
			return {X ^ vector.X, Y ^ vector.Y, Z ^ vector.Z};
		}

		inline Vector<3, N> operator<<(const Vector<3, N>& vector) const
		{
			return {X << vector.X, Y << vector.Y, Z << vector.Z};
		}

		inline Vector<3, N> operator>>(const Vector<3, N>& vector) const
		{
			return {X >> vector.X, Y >> vector.Y, Z >> vector.Z};
		}

		inline Vector<3, N>& operator+=(const Vector<3, N>& vector)
		{
			X += vector.X; Y += vector.Y; Z += vector.Z; return *this;
		}

		inline Vector<3, N>& operator-=(const Vector<3, N>& vector)
		{
			X -= vector.X; Y -= vector.Y; Z -= vector.Z; return *this;
		}

		inline Vector<3, N>& operator*=(const Vector<3, N>& vector)
		{
			X *= vector.X; Y *= vector.Y; Z *= vector.Z; return *this;
		}

		inline Vector<3, N>& operator/=(const Vector<3, N>& vector)
		{
			X /= vector.X; Y /= vector.Y; Z /= vector.Z; return *this;
		}

		inline Vector<3, N>& operator%=(const Vector<3, N>& vector)
		{
			X %= vector.X; Y %= vector.Y; Z %= vector.Z; return *this;
		}

		inline Vector<3, N>& operator&=(const Vector<3, N>& vector)
		{
			X &= vector.X; Y &= vector.Y; Z &= vector.Z; return *this;
		}

		inline Vector<3, N>& operator|=(const Vector<3, N>& vector)
		{
			X |= vector.X; Y |= vector.Y; Z |= vector.Z; return *this;
		}

		inline Vector<3, N>& operator^=(const Vector<3, N>& vector)
		{
			X ^= vector.X; Y ^= vector.Y; Z ^= vector.Z; return *this;
		}

		inline Vector<3, N>& operator<<=(const Vector<3, N>& vector)
		{
			X <<= vector.X; Y <<= vector.Y; Z <<= vector.Z; return *this;
		}

		inline Vector<3, N>& operator>>=(const Vector<3, N>& vector)
		{
			X >>= vector.X; Y >>= vector.Y; Z >>= vector.Z; return *this;
		}

		inline bool operator==(const Vector<3, N>& vector) const
		{
			return X == vector.X && Y == vector.Y && Z == vector.Z;
		}

		inline bool operator!=(const Vector<3, N>& vector) const
		{
			return X != vector.X || Y != vector.Y || Z != vector.Z;
		}

		inline Vector<3, N> operator+(N scalar) const
		{
			return {X + scalar, Y + scalar, Z + scalar};
		}

		inline Vector<3, N> operator-(N scalar) const
		{
			return {X - scalar, Y - scalar, Z - scalar};
		}

		inline Vector<3, N> operator*(N scalar) const
		{
			return {X * scalar, Y * scalar, Z * scalar};
		}

		inline Vector<3, N> operator/(N scalar) const
		{
			return {X / scalar, Y / scalar, Z / scalar};
		}

		inline Vector<3, N> operator%(N scalar) const
		{
			return {X % scalar, Y % scalar, Z % scalar};
		}

		inline Vector<3, N> operator&(N scalar) const
		{
			return {X & scalar, Y & scalar, Z & scalar};
		}

		inline Vector<3, N> operator|(N scalar) const
		{
			return {X | scalar, Y | scalar, Z | scalar};
		}

		inline Vector<3, N> operator^(N scalar) const
		{
			return {X ^ scalar, Y ^ scalar, Z ^ scalar};
		}

		inline Vector<3, N> operator<<(N scalar) const
		{
			return {X << scalar, Y << scalar, Z << scalar};
		}

		inline Vector<3, N> operator>>(N scalar) const
		{
			return {X >> scalar, Y >> scalar, Z >> scalar};
		}

		inline Vector<3, N>& operator+=(N scalar)
		{
			X += scalar; Y += scalar; Z += scalar; return *this;
		}

		inline Vector<3, N>& operator-=(N scalar)
		{
			X -= scalar; Y -= scalar; Z -= scalar; return *this;
		}

		inline Vector<3, N>& operator*=(N scalar)
		{
			X *= scalar; Y *= scalar; Z *= scalar; return *this;
		}

		inline Vector<3, N>& operator/=(N scalar)
		{
			X /= scalar; Y /= scalar; Z /= scalar; return *this;
		}

		inline Vector<3, N>& operator%=(N scalar)
		{
			X %= scalar; Y %= scalar; Z %= scalar; return *this;
		}

		inline Vector<3, N>& operator&=(N scalar)
		{
			X &= scalar; Y &= scalar; Z &= scalar; return *this;
		}

		inline Vector<3, N>& operator|=(N scalar)
		{
			X |= scalar; Y |= scalar; Z |= scalar; return *this;
		}

		inline Vector<3, N>& operator^=(N scalar)
		{
			X ^= scalar; Y ^= scalar; Z ^= scalar; return *this;
		}

		inline Vector<3, N>& operator<<=(N scalar)
		{
			X <<= scalar; Y <<= scalar; Z <<= scalar; return *this;
		}

		inline Vector<3, N>& operator>>=(N scalar)
		{
			X >>= scalar; Y >>= scalar; Z >>= scalar; return *this;
		}

		inline Vector<3, N> operator+() const
		{
			return {+X, +Y, +Z};
		}

		inline Vector<3, N> operator-() const
		{
			return {-X, -Y, -Z};
		}

		inline Vector<3, N> operator~() const
		{
			return {~X, ~Y, ~Z};
		}

		inline Vector<3, N>& operator++()
		{
			++X; ++Y; ++Z; return *this;
		}

		inline Vector<3, N>& operator--()
		{
			--X; --Y; --Z; return *this;
		}

		inline Vector<3, N> operator++(int)
		{
			auto oldValue = *this; ++X; ++Y; ++Z; return oldValue;
		}

		inline Vector<3, N> operator--(int)
		{
			auto oldValue = *this; --X; --Y; --Z; return oldValue;
		}

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << "(" << X << ", " << Y << ", " << Z << ")";
			return s.str();
		}
	};

	template<typename N> inline N Dot(const Vector<3, N>& v1, const Vector<3, N>& v2)
	{
		auto temp = v1 * v2; return temp.X + temp.Y + temp.Z;
	}

	template<typename N> inline Vector<3, N> Cross(const Vector<3, N>& v1, const Vector<3, N>& v2)
	{
		return {v1.Y * v2.Z - v2.Y * v1.Z,
				v1.Z * v2.X - v2.Z * v1.X,
				v1.X * v2.Y - v2.X * v1.Y};
	}

	template<typename N> inline Vector<3, N> operator+(N scalar, const Vector<3, N>& vector)
	{
		return {scalar + vector.X, scalar + vector.Y, scalar + vector.Z};
	}

	template<typename N> inline Vector<3, N> operator-(N scalar, const Vector<3, N>& vector)
	{
		return {scalar - vector.X, scalar - vector.Y, scalar - vector.Z};
	}

	template<typename N> inline Vector<3, N> operator*(N scalar, const Vector<3, N>& vector)
	{
		return {scalar * vector.X, scalar * vector.Y, scalar * vector.Z};
	}

	template<typename N> inline Vector<3, N> operator/(N scalar, const Vector<3, N>& vector)
	{
		return {scalar / vector.X, scalar / vector.Y, scalar / vector.Z};
	}

	template<typename N> inline Vector<3, N> operator%(N scalar, const Vector<3, N>& vector)
	{
		return {scalar % vector.X, scalar % vector.Y, scalar % vector.Z};
	}

	template<typename N> inline Vector<3, N> operator&(N scalar, const Vector<3, N>& vector)
	{
		return {scalar & vector.X, scalar & vector.Y, scalar & vector.Z};
	}

	template<typename N> inline Vector<3, N> operator|(N scalar, const Vector<3, N>& vector)
	{
		return {scalar | vector.X, scalar | vector.Y, scalar | vector.Z};
	}

	template<typename N> inline Vector<3, N> operator^(N scalar, const Vector<3, N>& vector)
	{
		return {scalar ^ vector.X, scalar ^ vector.Y, scalar ^ vector.Z};
	}

	template<typename N> inline Vector<3, N> operator<<(N scalar, const Vector<3, N>& vector)
	{
		return {scalar << vector.X, scalar << vector.Y, scalar << vector.Z};
	}

	template<typename N> inline Vector<3, N> operator>>(N scalar, const Vector<3, N>& vector)
	{
		return {scalar >> vector.X, scalar >> vector.Y, scalar >> vector.Z};
	}

	template<typename N, typename O> Vector<3, O> Apply(const Vector<3, N>& vector, O(*func)(N))
	{
		return {func(vector.X), func(vector.Y), func(vector.Z)};
	}
}
