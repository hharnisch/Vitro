namespace Vitro
{
	template<typename N> inline Vector<2, N> Vector<2, N>::operator+(const Vector<2, N>& vec) const
	{
		return {X + vec.X, Y + vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator-(const Vector<2, N>& vec) const
	{
		return {X - vec.X, Y - vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator*(const Vector<2, N>& vec) const
	{
		return {X * vec.X, Y * vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator/(const Vector<2, N>& vec) const
	{
		return {X / vec.X, Y / vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator%(const Vector<2, N>& vec) const
	{
		return {X % vec.X, Y % vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator&(const Vector<2, N>& vec) const
	{
		return {X & vec.X, Y & vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator|(const Vector<2, N>& vec) const
	{
		return {X | vec.X, Y | vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator^(const Vector<2, N>& vec) const
	{
		return {X ^ vec.X, Y ^ vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator<<(const Vector<2, N>& vec) const
	{
		return {X << vec.X, Y << vec.Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator>>(const Vector<2, N>& vec) const
	{
		return {X >> vec.X, Y >> vec.Y};
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator+=(const Vector<2, N>& vec)
	{
		X += vec.X; Y += vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator-=(const Vector<2, N>& vec)
	{
		X -= vec.X; Y -= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator*=(const Vector<2, N>& vec)
	{
		X *= vec.X; Y *= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator/=(const Vector<2, N>& vec)
	{
		X /= vec.X; Y /= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator%=(const Vector<2, N>& vec)
	{
		X %= vec.X; Y %= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator&=(const Vector<2, N>& vec)
	{
		X &= vec.X; Y &= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator|=(const Vector<2, N>& vec)
	{
		X |= vec.X; Y |= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator^=(const Vector<2, N>& vec)
	{
		X ^= vec.X; Y ^= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator<<=(const Vector<2, N>& vec)
	{
		X <<= vec.X; Y <<= vec.Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator>>=(const Vector<2, N>& vec)
	{
		X >>= vec.X; Y >>= vec.Y; return *this;
	}

	template<typename N> inline bool Vector<2, N>::operator==(const Vector<2, N>& vec) const
	{
		return X == vec.X && Y == vec.Y;
	}

	template<typename N> inline bool Vector<2, N>::operator!=(const Vector<2, N>& vec) const
	{
		return X != vec.X || Y != vec.Y;
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator+(N scalar) const
	{
		return {X + scalar, Y + scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator-(N scalar) const
	{
		return {X - scalar, Y - scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator*(N scalar) const
	{
		return {X * scalar, Y * scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator/(N scalar) const
	{
		return {X / scalar, Y / scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator%(N scalar) const
	{
		return {X % scalar, Y % scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator&(N scalar) const
	{
		return {X & scalar, Y & scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator|(N scalar) const
	{
		return {X | scalar, Y | scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator^(N scalar) const
	{
		return {X ^ scalar, Y ^ scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator<<(N scalar) const
	{
		return {X << scalar, Y << scalar};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator>>(N scalar) const
	{
		return {X >> scalar, Y >> scalar};
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator+=(N scalar)
	{
		X += scalar; Y += scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator-=(N scalar)
	{
		X -= scalar; Y -= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator*=(N scalar)
	{
		X *= scalar; Y *= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator/=(N scalar)
	{
		X /= scalar; Y /= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator%=(N scalar)
	{
		X %= scalar; Y %= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator&=(N scalar)
	{
		X &= scalar; Y &= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator|=(N scalar)
	{
		X |= scalar; Y |= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator^=(N scalar)
	{
		X ^= scalar; Y ^= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator<<=(N scalar)
	{
		X <<= scalar; Y <<= scalar; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator>>=(N scalar)
	{
		X >>= scalar; Y >>= scalar; return *this;
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator+() const
	{
		return {+X, +Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator-() const
	{
		return {-X, -Y};
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator~() const
	{
		return {~X, ~Y};
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator++()
	{
		++X; ++Y; return *this;
	}

	template<typename N> inline Vector<2, N>& Vector<2, N>::operator--()
	{
		--X; --Y; return *this;
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator++(int)
	{
		auto oldValue = *this; ++X; ++Y; return oldValue;
	}

	template<typename N> inline Vector<2, N> Vector<2, N>::operator--(int)
	{
		auto oldValue = *this; --X; --Y; return oldValue;
	}

	template<typename N> Vector<2, N>::operator std::string() const
	{
		std::stringstream s;
		s << "(" << X << ", " << Y << ")";
		return s.str();
	}

	template<typename N> inline N Dot(const Vector<2, N>& v1, const Vector<2, N>& v2)
	{
		auto temp = v1 * v2; return temp.X + temp.Y;
	}

	template<typename N> inline Vector<2, N> operator+(N scalar, const Vector<2, N>& vec)
	{
		return {scalar + vec.X, scalar + vec.Y};
	}

	template<typename N> inline Vector<2, N> operator-(N scalar, const Vector<2, N>& vec)
	{
		return {scalar - vec.X, scalar - vec.Y};
	}

	template<typename N> inline Vector<2, N> operator*(N scalar, const Vector<2, N>& vec)
	{
		return {scalar * vec.X, scalar * vec.Y};
	}

	template<typename N> inline Vector<2, N> operator/(N scalar, const Vector<2, N>& vec)
	{
		return {scalar / vec.X, scalar / vec.Y};
	}

	template<typename N> inline Vector<2, N> operator%(N scalar, const Vector<2, N>& vec)
	{
		return {scalar % vec.X, scalar % vec.Y};
	}

	template<typename N> inline Vector<2, N> operator&(N scalar, const Vector<2, N>& vec)
	{
		return {scalar & vec.X, scalar & vec.Y};
	}

	template<typename N> inline Vector<2, N> operator|(N scalar, const Vector<2, N>& vec)
	{
		return {scalar | vec.X, scalar | vec.Y};
	}

	template<typename N> inline Vector<2, N> operator^(N scalar, const Vector<2, N>& vec)
	{
		return {scalar ^ vec.X, scalar ^ vec.Y};
	}

	template<typename N> inline Vector<2, N> operator<<(N scalar, const Vector<2, N>& vec)
	{
		return {scalar << vec.X, scalar << vec.Y};
	}

	template<typename N> inline Vector<2, N> operator>>(N scalar, const Vector<2, N>& vec)
	{
		return {scalar >> vec.X, scalar >> vec.Y};
	}
}
