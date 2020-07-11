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

		Vector<4, N> operator+(const Vector<4, N>& vec) const;
		Vector<4, N> operator-(const Vector<4, N>& vec) const;
		Vector<4, N> operator*(const Vector<4, N>& vec) const;
		Vector<4, N> operator/(const Vector<4, N>& vec) const;
		Vector<4, N> operator%(const Vector<4, N>& vec) const;
		Vector<4, N> operator&(const Vector<4, N>& vec) const;
		Vector<4, N> operator|(const Vector<4, N>& vec) const;
		Vector<4, N> operator^(const Vector<4, N>& vec) const;
		Vector<4, N> operator<<(const Vector<4, N>& vec) const;
		Vector<4, N> operator>>(const Vector<4, N>& vec) const;
		Vector<4, N>& operator+=(const Vector<4, N>& vec);
		Vector<4, N>& operator-=(const Vector<4, N>& vec);
		Vector<4, N>& operator*=(const Vector<4, N>& vec);
		Vector<4, N>& operator/=(const Vector<4, N>& vec);
		Vector<4, N>& operator%=(const Vector<4, N>& vec);
		Vector<4, N>& operator&=(const Vector<4, N>& vec);
		Vector<4, N>& operator|=(const Vector<4, N>& vec);
		Vector<4, N>& operator^=(const Vector<4, N>& vec);
		Vector<4, N>& operator<<=(const Vector<4, N>& vec);
		Vector<4, N>& operator>>=(const Vector<4, N>& vec);
		bool operator==(const Vector<4, N>& vec) const;
		bool operator!=(const Vector<4, N>& vec) const;
		Vector<4, N> operator+(N scalar) const;
		Vector<4, N> operator-(N scalar) const;
		Vector<4, N> operator*(N scalar) const;
		Vector<4, N> operator/(N scalar) const;
		Vector<4, N> operator%(N scalar) const;
		Vector<4, N> operator&(N scalar) const;
		Vector<4, N> operator|(N scalar) const;
		Vector<4, N> operator^(N scalar) const;
		Vector<4, N> operator<<(N scalar) const;
		Vector<4, N> operator>>(N scalar) const;
		Vector<4, N>& operator+=(N scalar);
		Vector<4, N>& operator-=(N scalar);
		Vector<4, N>& operator*=(N scalar);
		Vector<4, N>& operator/=(N scalar);
		Vector<4, N>& operator%=(N scalar);
		Vector<4, N>& operator&=(N scalar);
		Vector<4, N>& operator|=(N scalar);
		Vector<4, N>& operator^=(N scalar);
		Vector<4, N>& operator<<=(N scalar);
		Vector<4, N>& operator>>=(N scalar);
		Vector<4, N> operator+() const;
		Vector<4, N> operator-() const;
		Vector<4, N> operator~() const;
		Vector<4, N>& operator++();
		Vector<4, N>& operator--();
		Vector<4, N> operator++(int);
		Vector<4, N> operator--(int);
		explicit operator std::string() const;
	};

	template<typename N> N Dot(const Vector<4, N>& v1, const Vector<4, N>& v2);
	template<typename N> Vector<4, N> operator+(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator-(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator*(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator/(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator%(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator&(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator|(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator^(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator<<(N scalar, const Vector<4, N>& vec);
	template<typename N> Vector<4, N> operator>>(N scalar, const Vector<4, N>& vec);
}

#include "Vector4.inl"
