#pragma once

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<2, N>
	{
		union { N X, R, S; };
		union { N Y, G, T; };

		Vector<2, N> operator+(const Vector<2, N>& vec) const;
		Vector<2, N> operator-(const Vector<2, N>& vec) const;
		Vector<2, N> operator*(const Vector<2, N>& vec) const;
		Vector<2, N> operator/(const Vector<2, N>& vec) const;
		Vector<2, N> operator%(const Vector<2, N>& vec) const;
		Vector<2, N> operator&(const Vector<2, N>& vec) const;
		Vector<2, N> operator|(const Vector<2, N>& vec) const;
		Vector<2, N> operator^(const Vector<2, N>& vec) const;
		Vector<2, N> operator<<(const Vector<2, N>& vec) const;
		Vector<2, N> operator>>(const Vector<2, N>& vec) const;
		Vector<2, N>& operator+=(const Vector<2, N>& vec);
		Vector<2, N>& operator-=(const Vector<2, N>& vec);
		Vector<2, N>& operator*=(const Vector<2, N>& vec);
		Vector<2, N>& operator/=(const Vector<2, N>& vec);
		Vector<2, N>& operator%=(const Vector<2, N>& vec);
		Vector<2, N>& operator&=(const Vector<2, N>& vec);
		Vector<2, N>& operator|=(const Vector<2, N>& vec);
		Vector<2, N>& operator^=(const Vector<2, N>& vec);
		Vector<2, N>& operator<<=(const Vector<2, N>& vec);
		Vector<2, N>& operator>>=(const Vector<2, N>& vec);
		bool operator==(const Vector<2, N>& vec) const;
		bool operator!=(const Vector<2, N>& vec) const;
		Vector<2, N> operator+(N scalar) const;
		Vector<2, N> operator-(N scalar) const;
		Vector<2, N> operator*(N scalar) const;
		Vector<2, N> operator/(N scalar) const;
		Vector<2, N> operator%(N scalar) const;
		Vector<2, N> operator&(N scalar) const;
		Vector<2, N> operator|(N scalar) const;
		Vector<2, N> operator^(N scalar) const;
		Vector<2, N> operator<<(N scalar) const;
		Vector<2, N> operator>>(N scalar) const;
		Vector<2, N>& operator+=(N scalar);
		Vector<2, N>& operator-=(N scalar);
		Vector<2, N>& operator*=(N scalar);
		Vector<2, N>& operator/=(N scalar);
		Vector<2, N>& operator%=(N scalar);
		Vector<2, N>& operator&=(N scalar);
		Vector<2, N>& operator|=(N scalar);
		Vector<2, N>& operator^=(N scalar);
		Vector<2, N>& operator<<=(N scalar);
		Vector<2, N>& operator>>=(N scalar);
		Vector<2, N> operator+() const;
		Vector<2, N> operator-() const;
		Vector<2, N> operator~() const;
		Vector<2, N>& operator++();
		Vector<2, N>& operator--();
		Vector<2, N> operator++(int);
		Vector<2, N> operator--(int);
		explicit operator std::string() const;
	};

	template<typename N> N Dot(const Vector<2, N>& v1, const Vector<2, N>& v2);
	template<typename N> Vector<2, N> operator+(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator-(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator*(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator/(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator%(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator&(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator|(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator^(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator<<(N scalar, const Vector<2, N>& vec);
	template<typename N> Vector<2, N> operator>>(N scalar, const Vector<2, N>& vec);
}

#include "Vector2.inl"
