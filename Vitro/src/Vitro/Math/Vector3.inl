namespace Vitro
{
	template<typename N> inline Vector<3, N> Vector<3, N>::operator+(const Vector<3, N>& vec) const
	{
		return {X + vec.X, Y + vec.Y, Z + vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator-(const Vector<3, N>& vec) const
	{
		return {X - vec.X, Y - vec.Y, Z - vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator*(const Vector<3, N>& vec) const
	{
		return {X * vec.X, Y * vec.Y, Z * vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator/(const Vector<3, N>& vec) const
	{
		return {X / vec.X, Y / vec.Y, Z / vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator%(const Vector<3, N>& vec) const
	{
		return {X % vec.X, Y % vec.Y, Z % vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator&(const Vector<3, N>& vec) const
	{
		return {X & vec.X, Y & vec.Y, Z & vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator|(const Vector<3, N>& vec) const
	{
		return {X | vec.X, Y | vec.Y, Z | vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator^(const Vector<3, N>& vec) const
	{
		return {X ^ vec.X, Y ^ vec.Y, Z ^ vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator<<(const Vector<3, N>& vec) const
	{
		return {X << vec.X, Y << vec.Y, Z << vec.Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator>>(const Vector<3, N>& vec) const
	{
		return {X >> vec.X, Y >> vec.Y, Z >> vec.Z};
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator+=(const Vector<3, N>& vec)
	{
		X += vec.X; Y += vec.Y; Z += vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator-=(const Vector<3, N>& vec)
	{
		X -= vec.X; Y -= vec.Y; Z -= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator*=(const Vector<3, N>& vec)
	{
		X *= vec.X; Y *= vec.Y; Z *= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator/=(const Vector<3, N>& vec)
	{
		X /= vec.X; Y /= vec.Y; Z /= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator%=(const Vector<3, N>& vec)
	{
		X %= vec.X; Y %= vec.Y; Z %= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator&=(const Vector<3, N>& vec)
	{
		X &= vec.X; Y &= vec.Y; Z &= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator|=(const Vector<3, N>& vec)
	{
		X |= vec.X; Y |= vec.Y; Z |= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator^=(const Vector<3, N>& vec)
	{
		X ^= vec.X; Y ^= vec.Y; Z ^= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator<<=(const Vector<3, N>& vec)
	{
		X <<= vec.X; Y <<= vec.Y; Z <<= vec.Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator>>=(const Vector<3, N>& vec)
	{
		X >>= vec.X; Y >>= vec.Y; Z >>= vec.Z; return *this;
	}

	template<typename N> inline bool Vector<3, N>::operator==(const Vector<3, N>& vec) const
	{
		return X == vec.X && Y == vec.Y && Z == vec.Z;
	}

	template<typename N> inline bool Vector<3, N>::operator!=(const Vector<3, N>& vec) const
	{
		return X != vec.X || Y != vec.Y || Z != vec.Z;
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator+(N scalar) const
	{
		return {X + scalar, Y + scalar, Z + scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator-(N scalar) const
	{
		return {X - scalar, Y - scalar, Z - scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator*(N scalar) const
	{
		return {X * scalar, Y * scalar, Z * scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator/(N scalar) const
	{
		return {X / scalar, Y / scalar, Z / scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator%(N scalar) const
	{
		return {X % scalar, Y % scalar, Z % scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator&(N scalar) const
	{
		return {X & scalar, Y & scalar, Z & scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator|(N scalar) const
	{
		return {X | scalar, Y | scalar, Z | scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator^(N scalar) const
	{
		return {X ^ scalar, Y ^ scalar, Z ^ scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator<<(N scalar) const
	{
		return {X << scalar, Y << scalar, Z << scalar};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator>>(N scalar) const
	{
		return {X >> scalar, Y >> scalar, Z >> scalar};
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator+=(N scalar)
	{
		X += scalar; Y += scalar; Z += scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator-=(N scalar)
	{
		X -= scalar; Y -= scalar; Z -= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator*=(N scalar)
	{
		X *= scalar; Y *= scalar; Z *= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator/=(N scalar)
	{
		X /= scalar; Y /= scalar; Z /= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator%=(N scalar)
	{
		X %= scalar; Y %= scalar; Z %= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator&=(N scalar)
	{
		X &= scalar; Y &= scalar; Z &= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator|=(N scalar)
	{
		X |= scalar; Y |= scalar; Z |= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator^=(N scalar)
	{
		X ^= scalar; Y ^= scalar; Z ^= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator<<=(N scalar)
	{
		X <<= scalar; Y <<= scalar; Z <<= scalar; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator>>=(N scalar)
	{
		X >>= scalar; Y >>= scalar; Z >>= scalar; return *this;
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator+() const
	{
		return {+X, +Y, +Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator-() const
	{
		return {-X, -Y, -Z};
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator~() const
	{
		return {~X, ~Y, ~Z};
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator++()
	{
		++X; ++Y; ++Z; return *this;
	}

	template<typename N> inline Vector<3, N>& Vector<3, N>::operator--()
	{
		--X; --Y; --Z; return *this;
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator++(int)
	{
		auto oldValue = *this; ++X; ++Y; ++Z; return oldValue;
	}

	template<typename N> inline Vector<3, N> Vector<3, N>::operator--(int)
	{
		auto oldValue = *this; --X; --Y; --Z; return oldValue;
	}

	template<typename N> Vector<3, N>::operator std::string() const
	{
		std::stringstream s;
		s << "(" << X << ", " << Y << ", " << Z << ")";
		return s.str();
	}

	template<typename N> inline N Dot(const Vector<3, N>& v1, const Vector<3, N>& v2)
	{
		auto temp = v1 * v2; return temp.X + temp.Y + temp.Z;
	}

	template<typename N> inline Vector<3, N> Cross(const Vector<3, N>& v1, const Vector<3, N>& v2)
	{
		return {v1.Y * v2.Z - v2.Y * v1.Z, v1.Z * v2.X - v2.Z * v1.X, v1.X * v2.Y - v2.X * v1.Y};
	}

	template<typename N> inline Vector<3, N> operator+(N scalar, const Vector<3, N>& vec)
	{
		return {scalar + vec.X, scalar + vec.Y, scalar + vec.Z};
	}

	template<typename N> inline Vector<3, N> operator-(N scalar, const Vector<3, N>& vec)
	{
		return {scalar - vec.X, scalar - vec.Y, scalar - vec.Z};
	}

	template<typename N> inline Vector<3, N> operator*(N scalar, const Vector<3, N>& vec)
	{
		return {scalar * vec.X, scalar * vec.Y, scalar * vec.Z};
	}

	template<typename N> inline Vector<3, N> operator/(N scalar, const Vector<3, N>& vec)
	{
		return {scalar / vec.X, scalar / vec.Y, scalar / vec.Z};
	}

	template<typename N> inline Vector<3, N> operator%(N scalar, const Vector<3, N>& vec)
	{
		return {scalar % vec.X, scalar % vec.Y, scalar % vec.Z};
	}

	template<typename N> inline Vector<3, N> operator&(N scalar, const Vector<3, N>& vec)
	{
		return {scalar & vec.X, scalar & vec.Y, scalar & vec.Z};
	}

	template<typename N> inline Vector<3, N> operator|(N scalar, const Vector<3, N>& vec)
	{
		return {scalar | vec.X, scalar | vec.Y, scalar | vec.Z};
	}

	template<typename N> inline Vector<3, N> operator^(N scalar, const Vector<3, N>& vec)
	{
		return {scalar ^ vec.X, scalar ^ vec.Y, scalar ^ vec.Z};
	}

	template<typename N> inline Vector<3, N> operator<<(N scalar, const Vector<3, N>& vec)
	{
		return {scalar << vec.X, scalar << vec.Y, scalar << vec.Z};
	}

	template<typename N> inline Vector<3, N> operator>>(N scalar, const Vector<3, N>& vec)
	{
		return {scalar >> vec.X, scalar >> vec.Y, scalar >> vec.Z};
	}
}
