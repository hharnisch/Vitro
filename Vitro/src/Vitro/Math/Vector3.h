#pragma once

namespace Vitro
{
	template<size_t D, typename N> struct Vector;

	template<typename N> struct Vector<3, N>
	{
		union { N X, R, S; };
		union { N Y, G, T; };
		union { N Z, B, P; };

		Vector<3, N> operator+(const Vector<3, N>& vec) const;
		Vector<3, N> operator-(const Vector<3, N>& vec) const;
		Vector<3, N> operator*(const Vector<3, N>& vec) const;
		Vector<3, N> operator/(const Vector<3, N>& vec) const;
		Vector<3, N> operator%(const Vector<3, N>& vec) const;
		Vector<3, N> operator&(const Vector<3, N>& vec) const;
		Vector<3, N> operator|(const Vector<3, N>& vec) const;
		Vector<3, N> operator^(const Vector<3, N>& vec) const;
		Vector<3, N> operator<<(const Vector<3, N>& vec) const;
		Vector<3, N> operator>>(const Vector<3, N>& vec) const;
		Vector<3, N>& operator+=(const Vector<3, N>& vec);
		Vector<3, N>& operator-=(const Vector<3, N>& vec);
		Vector<3, N>& operator*=(const Vector<3, N>& vec);
		Vector<3, N>& operator/=(const Vector<3, N>& vec);
		Vector<3, N>& operator%=(const Vector<3, N>& vec);
		Vector<3, N>& operator&=(const Vector<3, N>& vec);
		Vector<3, N>& operator|=(const Vector<3, N>& vec);
		Vector<3, N>& operator^=(const Vector<3, N>& vec);
		Vector<3, N>& operator<<=(const Vector<3, N>& vec);
		Vector<3, N>& operator>>=(const Vector<3, N>& vec);
		bool operator==(const Vector<3, N>& vec) const;
		bool operator!=(const Vector<3, N>& vec) const;
		Vector<3, N> operator+(N scalar) const;
		Vector<3, N> operator-(N scalar) const;
		Vector<3, N> operator*(N scalar) const;
		Vector<3, N> operator/(N scalar) const;
		Vector<3, N> operator%(N scalar) const;
		Vector<3, N> operator&(N scalar) const;
		Vector<3, N> operator|(N scalar) const;
		Vector<3, N> operator^(N scalar) const;
		Vector<3, N> operator<<(N scalar) const;
		Vector<3, N> operator>>(N scalar) const;
		Vector<3, N>& operator+=(N scalar);
		Vector<3, N>& operator-=(N scalar);
		Vector<3, N>& operator*=(N scalar);
		Vector<3, N>& operator/=(N scalar);
		Vector<3, N>& operator%=(N scalar);
		Vector<3, N>& operator&=(N scalar);
		Vector<3, N>& operator|=(N scalar);
		Vector<3, N>& operator^=(N scalar);
		Vector<3, N>& operator<<=(N scalar);
		Vector<3, N>& operator>>=(N scalar);
		Vector<3, N> operator+() const;
		Vector<3, N> operator-() const;
		Vector<3, N> operator~() const;
		Vector<3, N>& operator++();
		Vector<3, N>& operator--();
		Vector<3, N> operator++(int);
		Vector<3, N> operator--(int);
		explicit operator std::string() const;
	};

	template<typename N> N Dot(const Vector<3, N>& v1, const Vector<3, N>& v2);
	template<typename N> Vector<3, N> Cross(const Vector<3, N>& v1, const Vector<3, N>& v2);
	template<typename N> Vector<3, N> operator+(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator-(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator*(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator/(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator%(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator&(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator|(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator^(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator<<(N scalar, const Vector<3, N>& vec);
	template<typename N> Vector<3, N> operator>>(N scalar, const Vector<3, N>& vec);
}

#include "Vector3.inl"
