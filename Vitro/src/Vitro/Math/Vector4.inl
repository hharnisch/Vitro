namespace Vitro
{
	template<typename N> inline Vector<4, N> Vector<4, N>::operator+(const Vector<4, N>& vec) const
	{
		return {X + vec.X, Y + vec.Y, Z + vec.Z, W + vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator-(const Vector<4, N>& vec) const
	{
		return {X - vec.X, Y - vec.Y, Z - vec.Z, W - vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator*(const Vector<4, N>& vec) const
	{
		return {X * vec.X, Y * vec.Y, Z * vec.Z, W * vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator/(const Vector<4, N>& vec) const
	{
		return {X / vec.X, Y / vec.Y, Z / vec.Z, W / vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator%(const Vector<4, N>& vec) const
	{
		return {X % vec.X, Y % vec.Y, Z % vec.Z, W % vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator&(const Vector<4, N>& vec) const
	{
		return {X & vec.X, Y & vec.Y, Z & vec.Z, W & vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator|(const Vector<4, N>& vec) const
	{
		return {X | vec.X, Y | vec.Y, Z | vec.Z, W | vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator^(const Vector<4, N>& vec) const
	{
		return {X ^ vec.X, Y ^ vec.Y, Z ^ vec.Z, W ^ vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator<<(const Vector<4, N>& vec) const
	{
		return {X << vec.X, Y << vec.Y, Z << vec.Z, W << vec.W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator>>(const Vector<4, N>& vec) const
	{
		return {X >> vec.X, Y >> vec.Y, Z >> vec.Z, W >> vec.W};
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator+=(const Vector<4, N>& vec)
	{
		X += vec.X; Y += vec.Y; Z += vec.Z; W += vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator-=(const Vector<4, N>& vec)
	{
		X -= vec.X; Y -= vec.Y; Z -= vec.Z; W -= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator*=(const Vector<4, N>& vec)
	{
		X *= vec.X; Y *= vec.Y; Z *= vec.Z; W *= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator/=(const Vector<4, N>& vec)
	{
		X /= vec.X; Y /= vec.Y; Z /= vec.Z; W /= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator%=(const Vector<4, N>& vec)
	{
		X %= vec.X; Y %= vec.Y; Z %= vec.Z; W %= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator&=(const Vector<4, N>& vec)
	{
		X &= vec.X; Y &= vec.Y; Z &= vec.Z; W &= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator|=(const Vector<4, N>& vec)
	{
		X |= vec.X; Y |= vec.Y; Z |= vec.Z; W |= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator^=(const Vector<4, N>& vec)
	{
		X ^= vec.X; Y ^= vec.Y; Z ^= vec.Z; W ^= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator<<=(const Vector<4, N>& vec)
	{
		X <<= vec.X; Y <<= vec.Y; Z <<= vec.Z; W <<= vec.W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator>>=(const Vector<4, N>& vec)
	{
		X >>= vec.X; Y >>= vec.Y; Z >>= vec.Z; W >>= vec.W; return *this;
	}

	template<typename N> inline bool Vector<4, N>::operator==(const Vector<4, N>& vec) const
	{
		return X == vec.X && Y == vec.Y && Z == vec.Z && W == vec.W;
	}

	template<typename N> inline bool Vector<4, N>::operator!=(const Vector<4, N>& vec) const
	{
		return X != vec.X || Y != vec.Y || Z != vec.Z || W != vec.W;
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator+(N scalar) const
	{
		return {X + scalar, Y + scalar, Z + scalar, W + scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator-(N scalar) const
	{
		return {X - scalar, Y - scalar, Z - scalar, W - scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator*(N scalar) const
	{
		return {X * scalar, Y * scalar, Z * scalar, W * scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator/(N scalar) const
	{
		return {X / scalar, Y / scalar, Z / scalar, W / scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator%(N scalar) const
	{
		return {X % scalar, Y % scalar, Z % scalar, W % scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator&(N scalar) const
	{
		return {X & scalar, Y & scalar, Z & scalar, W & scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator|(N scalar) const
	{
		return {X | scalar, Y | scalar, Z | scalar, W | scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator^(N scalar) const
	{
		return {X ^ scalar, Y ^ scalar, Z ^ scalar, W ^ scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator<<(N scalar) const
	{
		return {X << scalar, Y << scalar, Z << scalar, W << scalar};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator>>(N scalar) const
	{
		return {X >> scalar, Y >> scalar, Z >> scalar, W >> scalar};
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator+=(N scalar)
	{
		X += scalar; Y += scalar; Z += scalar; W += scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator-=(N scalar)
	{
		X -= scalar; Y -= scalar; Z -= scalar; W -= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator*=(N scalar)
	{
		X *= scalar; Y *= scalar; Z *= scalar; W *= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator/=(N scalar)
	{
		X /= scalar; Y /= scalar; Z /= scalar; W /= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator%=(N scalar)
	{
		X %= scalar; Y %= scalar; Z %= scalar; W %= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator&=(N scalar)
	{
		X &= scalar; Y &= scalar; Z &= scalar; W &= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator|=(N scalar)
	{
		X |= scalar; Y |= scalar; Z |= scalar; W |= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator^=(N scalar)
	{
		X ^= scalar; Y ^= scalar; Z ^= scalar; W ^= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator<<=(N scalar)
	{
		X <<= scalar; Y <<= scalar; Z <<= scalar; W <<= scalar; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator>>=(N scalar)
	{
		X >>= scalar; Y >>= scalar; Z >>= scalar; W >>= scalar; return *this;
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator+() const
	{
		return {+X, +Y, +Z, +W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator-() const
	{
		return {-X, -Y, -Z, -W};
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator~() const
	{
		return {~X, ~Y, ~Z, ~W};
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator++()
	{
		++X; ++Y; ++Z; ++W; return *this;
	}

	template<typename N> inline Vector<4, N>& Vector<4, N>::operator--()
	{
		--X; --Y; --Z; --W; return *this;
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator++(int)
	{
		auto oldValue = *this; ++X; ++Y; ++Z; ++W; return oldValue;
	}

	template<typename N> inline Vector<4, N> Vector<4, N>::operator--(int)
	{
		auto oldValue = *this; --X; --Y; --Z; --W; return oldValue;
	}

	template<typename N> Vector<4, N>::operator std::string() const
	{
		std::stringstream s;
		s << "(" << X << ", " << Y << ", " << Z << ", " << W << ")";
		return s.str();
	}

	template<typename N> inline N Dot(const Vector<4, N>& left, const Vector<4, N>& right)
	{
		auto temp = left * right; return temp.X + temp.Y + temp.Z + temp.W;
	}

	template<typename N> inline Vector<4, N> operator+(N scalar, const Vector<4, N>& vec)
	{
		return {scalar + vec.X, scalar + vec.Y, scalar + vec.Z, scalar + vec.W};
	}

	template<typename N> inline Vector<4, N> operator-(N scalar, const Vector<4, N>& vec)
	{
		return {scalar - vec.X, scalar - vec.Y, scalar - vec.Z, scalar - vec.W};
	}

	template<typename N> inline Vector<4, N> operator*(N scalar, const Vector<4, N>& vec)
	{
		return {scalar * vec.X, scalar * vec.Y, scalar * vec.Z, scalar * vec.W};
	}

	template<typename N> inline Vector<4, N> operator/(N scalar, const Vector<4, N>& vec)
	{
		return {scalar / vec.X, scalar / vec.Y, scalar / vec.Z, scalar / vec.W};
	}

	template<typename N> inline Vector<4, N> operator%(N scalar, const Vector<4, N>& vec)
	{
		return {scalar % vec.X, scalar % vec.Y, scalar % vec.Z, scalar % vec.W};
	}

	template<typename N> inline Vector<4, N> operator&(N scalar, const Vector<4, N>& vec)
	{
		return {scalar & vec.X, scalar & vec.Y, scalar & vec.Z, scalar & vec.W};
	}

	template<typename N> inline Vector<4, N> operator|(N scalar, const Vector<4, N>& vec)
	{
		return {scalar | vec.X, scalar | vec.Y, scalar | vec.Z, scalar | vec.W};
	}

	template<typename N> inline Vector<4, N> operator^(N scalar, const Vector<4, N>& vec)
	{
		return {scalar ^ vec.X, scalar ^ vec.Y, scalar ^ vec.Z, scalar ^ vec.W};
	}

	template<typename N> inline Vector<4, N> operator<<(N scalar, const Vector<4, N>& vec)
	{
		return {scalar << vec.X, scalar << vec.Y, scalar << vec.Z, scalar << vec.W};
	}

	template<typename N> inline Vector<4, N> operator>>(N scalar, const Vector<4, N>& vec)
	{
		return {scalar >> vec.X, scalar >> vec.Y, scalar >> vec.Z, scalar >> vec.W};
	}
}
