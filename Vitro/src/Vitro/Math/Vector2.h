#pragma once

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<2, N>
	{
		union { N X, R, S; };
		union { N Y, G, T; };

		inline Vector() = default;
		inline Vector(N x, N y) : X(x), Y(y) {}
		inline Vector(N scalar) : X(scalar), Y(scalar) {}

		template<typename O1, typename O2>
		inline Vector(O1 x, O2 y)
			: X(static_cast<N>(x)), Y(static_cast<N>(y))
		{}

		template<typename O>
		inline Vector(O scalar) : X(static_cast<N>(scalar)), Y(static_cast<N>(scalar))
		{}

		template<typename O>
		inline Vector(const Vector<2, O>& other) : X(other.X), Y(other.Y) {}

		inline N& operator[](size_t index)
		{
			switch(index)
			{
				case 0: return X;
				case 1: return Y;
				default: throw std::out_of_range("Vector index out of range.");
			}
		}

		inline Vector<2, N> operator+(const Vector<2, N>& vector) const
		{
			return {X + vector.X, Y + vector.Y};
		}

		inline Vector<2, N> operator-(const Vector<2, N>& vector) const
		{
			return {X - vector.X, Y - vector.Y};
		}

		inline Vector<2, N> operator*(const Vector<2, N>& vector) const
		{
			return {X * vector.X, Y * vector.Y};
		}

		inline Vector<2, N> operator/(const Vector<2, N>& vector) const
		{
			return {X / vector.X, Y / vector.Y};
		}

		inline Vector<2, N> operator%(const Vector<2, N>& vector) const
		{
			return {X % vector.X, Y % vector.Y};
		}
		inline Vector<2, N> operator&(const Vector<2, N>& vector) const
		{
			return {X & vector.X, Y & vector.Y};
		}

		inline Vector<2, N> operator|(const Vector<2, N>& vector) const
		{
			return {X | vector.X, Y | vector.Y};
		}

		inline Vector<2, N> operator^(const Vector<2, N>& vector) const
		{
			return {X ^ vector.X, Y ^ vector.Y};
		}

		inline Vector<2, N> operator<<(const Vector<2, N>& vector) const
		{
			return {X << vector.X, Y << vector.Y};
		}

		inline Vector<2, N> operator>>(const Vector<2, N>& vector) const
		{
			return {X >> vector.X, Y >> vector.Y};
		}

		inline Vector<2, N>& operator+=(const Vector<2, N>& vector)
		{
			X += vector.X; Y += vector.Y; return *this;
		}

		inline Vector<2, N>& operator-=(const Vector<2, N>& vector)
		{
			X -= vector.X; Y -= vector.Y; return *this;
		}

		inline Vector<2, N>& operator*=(const Vector<2, N>& vector)
		{
			X *= vector.X; Y *= vector.Y; return *this;
		}

		inline Vector<2, N>& operator/=(const Vector<2, N>& vector)
		{
			X /= vector.X; Y /= vector.Y; return *this;
		}

		inline Vector<2, N>& operator%=(const Vector<2, N>& vector)
		{
			X %= vector.X; Y %= vector.Y; return *this;
		}

		inline Vector<2, N>& operator&=(const Vector<2, N>& vector)
		{
			X &= vector.X; Y &= vector.Y; return *this;
		}

		inline Vector<2, N>& operator|=(const Vector<2, N>& vector)
		{
			X |= vector.X; Y |= vector.Y; return *this;
		}

		inline Vector<2, N>& operator^=(const Vector<2, N>& vector)
		{
			X ^= vector.X; Y ^= vector.Y; return *this;
		}

		inline Vector<2, N>& operator<<=(const Vector<2, N>& vector)
		{
			X <<= vector.X; Y <<= vector.Y; return *this;
		}

		inline Vector<2, N>& operator>>=(const Vector<2, N>& vector)
		{
			X >>= vector.X; Y >>= vector.Y; return *this;
		}

		inline bool operator==(const Vector<2, N>& vector) const
		{
			return X == vector.X && Y == vector.Y;
		}

		inline bool operator!=(const Vector<2, N>& vector) const
		{
			return X != vector.X || Y != vector.Y;
		}

		inline Vector<2, N> operator+(N scalar) const
		{
			return {X + scalar, Y + scalar};
		}

		inline Vector<2, N> operator-(N scalar) const
		{
			return {X - scalar, Y - scalar};
		}

		inline Vector<2, N> operator*(N scalar) const
		{
			return {X * scalar, Y * scalar};
		}

		inline Vector<2, N> operator/(N scalar) const
		{
			return {X / scalar, Y / scalar};
		}

		inline Vector<2, N> operator%(N scalar) const
		{
			return {X % scalar, Y % scalar};
		}

		inline Vector<2, N> operator&(N scalar) const
		{
			return {X & scalar, Y & scalar};
		}

		inline Vector<2, N> operator|(N scalar) const
		{
			return {X | scalar, Y | scalar};
		}

		inline Vector<2, N> operator^(N scalar) const
		{
			return {X ^ scalar, Y ^ scalar};
		}

		inline Vector<2, N> operator<<(N scalar) const
		{
			return {X << scalar, Y << scalar};
		}

		inline Vector<2, N> operator>>(N scalar) const
		{
			return {X >> scalar, Y >> scalar};
		}

		inline Vector<2, N>& operator+=(N scalar)
		{
			X += scalar; Y += scalar; return *this;
		}

		inline Vector<2, N>& operator-=(N scalar)
		{
			X -= scalar; Y -= scalar; return *this;
		}

		inline Vector<2, N>& operator*=(N scalar)
		{
			X *= scalar; Y *= scalar; return *this;
		}

		inline Vector<2, N>& operator/=(N scalar)
		{
			X /= scalar; Y /= scalar; return *this;
		}

		inline Vector<2, N>& operator%=(N scalar)
		{
			X %= scalar; Y %= scalar; return *this;
		}

		inline Vector<2, N>& operator&=(N scalar)
		{
			X &= scalar; Y &= scalar; return *this;
		}

		inline Vector<2, N>& operator|=(N scalar)
		{
			X |= scalar; Y |= scalar; return *this;
		}

		inline Vector<2, N>& operator^=(N scalar)
		{
			X ^= scalar; Y ^= scalar; return *this;
		}

		inline Vector<2, N>& operator<<=(N scalar)
		{
			X <<= scalar; Y <<= scalar; return *this;
		}

		inline Vector<2, N>& operator>>=(N scalar)
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
			s << "(" << X << ", " << Y << ")";
			return s.str();
		}
	};

	template<typename N> inline N Dot(const Vector<2, N>& v1, const Vector<2, N>& v2)
	{
		auto temp = v1 * v2; return temp.X + temp.Y;
	}

	template<typename N> inline Vector<2, N> operator+(N scalar, const Vector<2, N>& vector)
	{
		return {scalar + vector.X, scalar + vector.Y};
	}

	template<typename N> inline Vector<2, N> operator-(N scalar, const Vector<2, N>& vector)
	{
		return {scalar - vector.X, scalar - vector.Y};
	}

	template<typename N> inline Vector<2, N> operator*(N scalar, const Vector<2, N>& vector)
	{
		return {scalar * vector.X, scalar * vector.Y};
	}

	template<typename N> inline Vector<2, N> operator/(N scalar, const Vector<2, N>& vector)
	{
		return {scalar / vector.X, scalar / vector.Y};
	}

	template<typename N> inline Vector<2, N> operator%(N scalar, const Vector<2, N>& vector)
	{
		return {scalar % vector.X, scalar % vector.Y};
	}

	template<typename N> inline Vector<2, N> operator&(N scalar, const Vector<2, N>& vector)
	{
		return {scalar & vector.X, scalar & vector.Y};
	}

	template<typename N> inline Vector<2, N> operator|(N scalar, const Vector<2, N>& vector)
	{
		return {scalar | vector.X, scalar | vector.Y};
	}

	template<typename N> inline Vector<2, N> operator^(N scalar, const Vector<2, N>& vector)
	{
		return {scalar ^ vector.X, scalar ^ vector.Y};
	}

	template<typename N> inline Vector<2, N> operator<<(N scalar, const Vector<2, N>& vector)
	{
		return {scalar << vector.X, scalar << vector.Y};
	}

	template<typename N> inline Vector<2, N> operator>>(N scalar, const Vector<2, N>& vector)
	{
		return {scalar >> vector.X, scalar >> vector.Y};
	}

	template<typename N, typename O> Vector<2, O> Apply(const Vector<2, N>& vector, O(*func)(N))
	{
		return {func(vector.X), func(vector.Y)};
	}
}
