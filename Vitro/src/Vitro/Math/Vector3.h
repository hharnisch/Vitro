#pragma once

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<3, N>
	{
		union
		{
			struct { N X, Y, Z; };
			struct { N R, G, B; };
			struct { N S, T, P; };
		};

		inline Vector() = default;

		template<typename O0, typename O1, typename O2>
		inline Vector(O0 x, O1 y, O2 z) : X(static_cast<N>(x)), Y(static_cast<N>(y)),
			Z(static_cast<N>(z))
		{}

		template<typename O>
		inline Vector(O scalar) : Vector(static_cast<N>(scalar), static_cast<N>(scalar),
										 static_cast<N>(scalar))
		{}

		template<typename O>
		inline Vector(const Vector<3, O>& other) : Vector(other.X, other.Y, other.Z) {}

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

	template<typename N> inline N Dot(const Vector<3, N>& lv, const Vector<3, N>& rv)
	{
		auto temp = lv * rv; return temp.X + temp.Y + temp.Z;
	}

	template<typename N> inline Vector<3, N> Cross(const Vector<3, N>& lv, const Vector<3, N>& rv)
	{
		return {lv.Y * rv.Z - rv.Y * lv.Z,
				lv.Z * rv.X - rv.Z * lv.X,
				lv.X * rv.Y - rv.X * lv.Y};
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
