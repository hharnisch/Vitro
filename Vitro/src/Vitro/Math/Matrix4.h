﻿#pragma once

#include "Vitro/Math/Vector2.h"

#define $Scalar typename = typename std::enable_if_t<std::is_arithmetic_v<O>, O>

namespace Vitro
{
	template<size_t R, size_t C, typename N> struct Matrix;

	template<size_t R, typename N> struct Matrix<R, 4, N>
	{
	private:
		typedef Vector<R, N> Col;
		Col Val[4];

	public:
		template<typename = typename std::enable_if_t<R == 2>, typename O0, typename O1,
			typename O2, typename O3, typename O4, typename O5, typename O6, typename O7>
			inline Matrix(O0 x0, O1 y0,
						  O2 x1, O3 y1,
						  O4 x2, O5 y2,
						  O6 x3, O7 y3)
			: Val{Col(x0, y0), Col(x1, y1), Col(x2, y2), Col(x3, y3)}
		{}

		template<typename = typename std::enable_if_t<R == 3>, typename O0, typename O1,
			typename O2, typename O3, typename O4, typename O5, typename O6, typename O7,
			typename O8, typename O9, typename O10, typename O11>
			inline Matrix(O0 x0, O1 y0, O2 z0,
						  O3 x1, O4 y1, O5 z1,
						  O6 x2, O7 y2, O8 z2,
						  O9 x3, O10 y3, O11 z3)
			: Val{Col(x0, y0, z0), Col(x1, y1, z1), Col(x2, y2, z2), Col(x3, y3, z3)}
		{}

		template<typename = typename std::enable_if_t<R == 4>, typename O0, typename O1,
			typename O2, typename O3, typename O4, typename O5, typename O6, typename O7,
			typename O8, typename O9, typename O10, typename O11, typename O12, typename O13,
			typename O14, typename O15> inline Matrix(O0 x0, O1 y0, O2 z0, O3 w0,
													  O4 x1, O5 y1, O6 z1, O7 w1,
													  O8 x2, O9 y2, O10 z2, O11 w2,
													  O12 x3, O13 y3, O14 z3, O15 w3)
			: Val{Col(x0, y0, z0, w0), Col(x1, y1, z1, w1), Col(x2, y2, z2, w2),
				   Col(x3, y3, z3, w3)}
		{}

		template<typename = typename std::enable_if_t<R == 4>>
		inline constexpr Matrix() : Matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1) {}

		template<typename O>
		inline Matrix(O scalar) : Val{Col(scalar), Col(scalar), Col(scalar), Col(scalar)} {}

		template<typename O0, typename O1, typename O2, typename O3>
		inline Matrix(const Vector<R, O0>& v0, const Vector<R, O1>& v1, const Vector<R, O2>& v2,
					  const Vector<R, O3>& v3)
			: Val{v0, v1, v2, v3}
		{}

		inline Col& operator[](size_t index)
		{
			AssertArrayRange(Val, index, "Matrix column");
			return Val[index];
		}

		inline const Col& operator[](size_t index) const
		{
			AssertArrayRange(Val, index, "Matrix column");
			return Val[index];
		}

		template<typename O> inline Matrix<R, 4, N> operator+(const Matrix<R, 4, O>& m) const
		{
			return {Val[0] + m[0], Val[1] + m[1], Val[2] + m[2], Val[3] + m[3]};
		}

		template<typename O> inline Matrix<R, 4, N> operator-(const Matrix<R, 4, O>& m) const
		{
			return {Val[0] - m[0], Val[1] - m[1], Val[2] - m[2], Val[3] - m[3]};
		}

		template<typename O> inline Matrix<R, 4, N>& operator+=(const Matrix<R, 4, O>& m)
		{
			Val[0] += m[0]; Val[1] += m[1]; Val[2] += m[2]; Val[3] += m[3]; return *this;
		}

		template<typename O> inline Matrix<R, 4, N>& operator-=(const Matrix<R, 4, O>& m)
		{
			Val[0] -= m[0]; Val[1] -= m[1]; Val[2] -= m[2]; Val[3] -= m[3]; return *this;
		}

		template<typename O> inline bool operator==(const Matrix<R, 4, O>& m) const
		{
			return Val[0] == m[0] && Val[1] == m[1] && Val[2] == m[2] && Val[3] == m[3];
		}

		template<typename O> inline bool operator!=(const Matrix<R, 4, O>& m) const
		{
			return Val[0] != m[0] || Val[1] != m[1] || Val[2] != m[2] || Val[3] != m[3];
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N> operator+(O scalar) const
		{
			return {Val[0] + scalar, Val[1] + scalar, Val[2] + scalar, Val[3] + scalar};
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N> operator-(O scalar) const
		{
			return {Val[0] - scalar, Val[1] - scalar, Val[2] - scalar, Val[3] - scalar};
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N> operator*(O scalar) const
		{
			return {Val[0] * scalar, Val[1] * scalar, Val[2] * scalar, Val[3] * scalar};
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N> operator/(O scalar) const
		{
			return {Val[0] / scalar, Val[1] / scalar, Val[2] / scalar, Val[3] / scalar};
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N>& operator+=(O scalar)
		{
			Val[0] += scalar; Val[1] += scalar; Val[2] += scalar; Val[3] += scalar; return *this;
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N>& operator-=(O scalar)
		{
			Val[0] -= scalar; Val[1] -= scalar; Val[2] -= scalar; Val[3] -= scalar; return *this;
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N>& operator*=(O scalar)
		{
			Val[0] *= scalar; Val[1] *= scalar; Val[2] *= scalar; Val[3] *= scalar; return *this;
		}

		template<typename O, $Scalar> inline Matrix<R, 4, N>& operator/=(O scalar)
		{
			Val[0] /= scalar; Val[1] /= scalar; Val[2] /= scalar; Val[3] /= scalar; return *this;
		}

		inline Matrix<R, 4, N> operator+() const
		{
			return {+Val[0], +Val[1], +Val[2], +Val[3]};
		}

		inline Matrix<R, 4, N> operator-() const
		{
			return {-Val[0], -Val[1], -Val[2], -Val[3]};
		}

		inline Matrix<R, 4, N>& operator++()
		{
			++Val[0]; ++Val[1]; ++Val[2]; ++Val[3]; return *this;
		}

		inline Matrix<R, 4, N>& operator--()
		{
			--Val[0]; --Val[1]; --Val[2]; --Val[3]; return *this;
		}

		inline Matrix<R, 4, N> operator++(int)
		{
			auto oldValue = *this; ++Val[0]; ++Val[1]; ++Val[2]; ++Val[3]; return oldValue;
		}

		inline Matrix<R, 4, N> operator--(int)
		{
			auto oldValue = *this; --Val[0]; --Val[1]; --Val[2]; --Val[3]; return oldValue;
		}

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << "[" << static_cast<std::string>(Val[0]) << ", ";
			s << static_cast<std::string>(Val[1]) << ", ";
			s << static_cast<std::string>(Val[2]) << ", ";
			s << static_cast<std::string>(Val[3]) << "]";
			return s.str();
		}
	};

	template<typename N, typename O>
	inline Matrix<2, 2, N> operator*(const Matrix<2, 4, N>& lm, const Matrix<4, 2, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W};
	}

	template<typename N, typename O>
	inline Matrix<2, 3, N> operator*(const Matrix<2, 4, N>& lm, const Matrix<4, 3, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].X * rm[2].X + lm[1].X * rm[2].Y + lm[2].X * rm[2].Z + lm[3].X * rm[2].W,
				lm[0].Y * rm[2].X + lm[1].Y * rm[2].Y + lm[2].Y * rm[2].Z + lm[3].Y * rm[2].W};
	}

	template<typename N, typename O>
	inline Matrix<2, 4, N> operator*(const Matrix<2, 4, N>& lm, const Matrix<4, 4, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].X * rm[2].X + lm[1].X * rm[2].Y + lm[2].X * rm[2].Z + lm[3].X * rm[2].W,
				lm[0].Y * rm[2].X + lm[1].Y * rm[2].Y + lm[2].Y * rm[2].Z + lm[3].Y * rm[2].W,
				lm[0].X * rm[3].X + lm[1].X * rm[3].Y + lm[2].X * rm[3].Z + lm[3].X * rm[3].W,
				lm[0].Y * rm[3].X + lm[1].Y * rm[3].Y + lm[2].Y * rm[3].Z + lm[3].Y * rm[3].W};
	}

	template<typename N, typename O>
	inline Matrix<3, 2, N> operator*(const Matrix<3, 4, N>& lm, const Matrix<4, 2, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].Z * rm[0].X + lm[1].Z * rm[0].Y + lm[2].Z * rm[0].Z + lm[3].Z * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].Z * rm[1].X + lm[1].Z * rm[1].Y + lm[2].Z * rm[1].Z + lm[3].Z * rm[1].W};
	}

	template<typename N, typename O>
	inline Matrix<3, 3, N> operator*(const Matrix<3, 4, N>& lm, const Matrix<4, 3, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].Z * rm[0].X + lm[1].Z * rm[0].Y + lm[2].Z * rm[0].Z + lm[3].Z * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].Z * rm[1].X + lm[1].Z * rm[1].Y + lm[2].Z * rm[1].Z + lm[3].Z * rm[1].W,
				lm[0].X * rm[2].X + lm[1].X * rm[2].Y + lm[2].X * rm[2].Z + lm[3].X * rm[2].W,
				lm[0].Y * rm[2].X + lm[1].Y * rm[2].Y + lm[2].Y * rm[2].Z + lm[3].Y * rm[2].W,
				lm[0].Z * rm[2].X + lm[1].Z * rm[2].Y + lm[2].Z * rm[2].Z + lm[3].Z * rm[2].W};
	}

	template<typename N, typename O>
	inline Matrix<3, 4, N> operator*(const Matrix<3, 4, N>& lm, const Matrix<4, 4, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].Z * rm[0].X + lm[1].Z * rm[0].Y + lm[2].Z * rm[0].Z + lm[3].Z * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].Z * rm[1].X + lm[1].Z * rm[1].Y + lm[2].Z * rm[1].Z + lm[3].Z * rm[1].W,
				lm[0].X * rm[2].X + lm[1].X * rm[2].Y + lm[2].X * rm[2].Z + lm[3].X * rm[2].W,
				lm[0].Y * rm[2].X + lm[1].Y * rm[2].Y + lm[2].Y * rm[2].Z + lm[3].Y * rm[2].W,
				lm[0].Z * rm[2].X + lm[1].Z * rm[2].Y + lm[2].Z * rm[2].Z + lm[3].Z * rm[2].W,
				lm[0].X * rm[3].X + lm[1].X * rm[3].Y + lm[2].X * rm[3].Z + lm[3].X * rm[3].W,
				lm[0].Y * rm[3].X + lm[1].Y * rm[3].Y + lm[2].Y * rm[3].Z + lm[3].Y * rm[3].W,
				lm[0].Z * rm[3].X + lm[1].Z * rm[3].Y + lm[2].Z * rm[3].Z + lm[3].Z * rm[3].W};
	}

	template<typename N, typename O>
	inline Matrix<4, 2, N> operator*(const Matrix<4, 4, N>& lm, const Matrix<4, 2, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].Z * rm[0].X + lm[1].Z * rm[0].Y + lm[2].Z * rm[0].Z + lm[3].Z * rm[0].W,
				lm[0].W * rm[0].X + lm[1].W * rm[0].Y + lm[2].W * rm[0].Z + lm[3].W * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].Z * rm[1].X + lm[1].Z * rm[1].Y + lm[2].Z * rm[1].Z + lm[3].Z * rm[1].W,
				lm[0].W * rm[1].X + lm[1].W * rm[1].Y + lm[2].W * rm[1].Z + lm[3].W * rm[1].W};
	}

	template<typename N, typename O>
	inline Matrix<4, 3, N> operator*(const Matrix<4, 4, N>& lm, const Matrix<4, 3, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].Z * rm[0].X + lm[1].Z * rm[0].Y + lm[2].Z * rm[0].Z + lm[3].Z * rm[0].W,
				lm[0].W * rm[0].X + lm[1].W * rm[0].Y + lm[2].W * rm[0].Z + lm[3].W * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].Z * rm[1].X + lm[1].Z * rm[1].Y + lm[2].Z * rm[1].Z + lm[3].Z * rm[1].W,
				lm[0].W * rm[1].X + lm[1].W * rm[1].Y + lm[2].W * rm[1].Z + lm[3].W * rm[1].W,
				lm[0].X * rm[2].X + lm[1].X * rm[2].Y + lm[2].X * rm[2].Z + lm[3].X * rm[2].W,
				lm[0].Y * rm[2].X + lm[1].Y * rm[2].Y + lm[2].Y * rm[2].Z + lm[3].Y * rm[2].W,
				lm[0].Z * rm[2].X + lm[1].Z * rm[2].Y + lm[2].Z * rm[2].Z + lm[3].Z * rm[2].W,
				lm[0].W * rm[2].X + lm[1].W * rm[2].Y + lm[2].W * rm[2].Z + lm[3].W * rm[2].W};
	}

	template<typename N, typename O>
	inline Matrix<4, 4, N> operator*(const Matrix<4, 4, N>& lm, const Matrix<4, 4, O>& rm)
	{
		return {lm[0].X * rm[0].X + lm[1].X * rm[0].Y + lm[2].X * rm[0].Z + lm[3].X * rm[0].W,
				lm[0].Y * rm[0].X + lm[1].Y * rm[0].Y + lm[2].Y * rm[0].Z + lm[3].Y * rm[0].W,
				lm[0].Z * rm[0].X + lm[1].Z * rm[0].Y + lm[2].Z * rm[0].Z + lm[3].Z * rm[0].W,
				lm[0].W * rm[0].X + lm[1].W * rm[0].Y + lm[2].W * rm[0].Z + lm[3].W * rm[0].W,
				lm[0].X * rm[1].X + lm[1].X * rm[1].Y + lm[2].X * rm[1].Z + lm[3].X * rm[1].W,
				lm[0].Y * rm[1].X + lm[1].Y * rm[1].Y + lm[2].Y * rm[1].Z + lm[3].Y * rm[1].W,
				lm[0].Z * rm[1].X + lm[1].Z * rm[1].Y + lm[2].Z * rm[1].Z + lm[3].Z * rm[1].W,
				lm[0].W * rm[1].X + lm[1].W * rm[1].Y + lm[2].W * rm[1].Z + lm[3].W * rm[1].W,
				lm[0].X * rm[2].X + lm[1].X * rm[2].Y + lm[2].X * rm[2].Z + lm[3].X * rm[2].W,
				lm[0].Y * rm[2].X + lm[1].Y * rm[2].Y + lm[2].Y * rm[2].Z + lm[3].Y * rm[2].W,
				lm[0].Z * rm[2].X + lm[1].Z * rm[2].Y + lm[2].Z * rm[2].Z + lm[3].Z * rm[2].W,
				lm[0].W * rm[2].X + lm[1].W * rm[2].Y + lm[2].W * rm[2].Z + lm[3].W * rm[2].W,
				lm[0].X * rm[3].X + lm[1].X * rm[3].Y + lm[2].X * rm[3].Z + lm[3].X * rm[3].W,
				lm[0].Y * rm[3].X + lm[1].Y * rm[3].Y + lm[2].Y * rm[3].Z + lm[3].Y * rm[3].W,
				lm[0].Z * rm[3].X + lm[1].Z * rm[3].Y + lm[2].Z * rm[3].Z + lm[3].Z * rm[3].W,
				lm[0].W * rm[3].X + lm[1].W * rm[3].Y + lm[2].W * rm[3].Z + lm[3].W * rm[3].W};
	}

	template<typename N, typename O>
	inline Vector<2, N> operator*(const Matrix<2, 4, N>& m, const Vector<4, O>& v)
	{
		return {m[0].X * v.X + m[1].X * v.Y + m[2].X * v.Z + m[3].X * v.W,
				m[0].Y * v.X + m[1].Y * v.Y + m[2].Y * v.Z + m[3].Y * v.W};
	}

	template<typename N, typename O>
	inline Vector<4, N> operator*(const Vector<2, O>& v, const Matrix<2, 4, N>& m)
	{
		return {v.X * m[0].X + v.Y * m[0].Y,
				v.X * m[1].X + v.Y * m[1].Y,
				v.X * m[2].X + v.Y * m[2].Y,
				v.X * m[3].X + v.Y * m[3].Y};
	}

	template<typename N, typename O>
	inline Vector<3, N> operator*(const Matrix<3, 4, N>& m, const Vector<4, O>& v)
	{
		return {m[0].X * v.X + m[1].X * v.Y + m[2].X * v.Z + m[3].X * v.W,
				m[0].Y * v.X + m[1].Y * v.Y + m[2].Y * v.Z + m[3].Y * v.W,
				m[0].Z * v.X + m[1].Z * v.Y + m[2].Z * v.Z + m[3].Z * v.W};
	}

	template<typename N, typename O>
	inline Vector<4, N> operator*(const Vector<3, O>& v, const Matrix<3, 4, N>& m)
	{
		return {v.X * m[0].X + v.Y * m[0].Y + v.Z * m[0].Z,
				v.X * m[1].X + v.Y * m[1].Y + v.Z * m[1].Z,
				v.X * m[2].X + v.Y * m[2].Y + v.Z * m[2].Z,
				v.X * m[3].X + v.Y * m[3].Y + v.Z * m[3].Z};
	}

	template<typename N, typename O>
	inline Vector<4, N> operator*(const Matrix<4, 4, N>& m, const Vector<4, O>& v)
	{
		return {m[0].X * v.X + m[1].X * v.Y + m[2].X * v.Z + m[3].X * v.W,
				m[0].Y * v.X + m[1].Y * v.Y + m[2].Y * v.Z + m[3].Y * v.W,
				m[0].Z * v.X + m[1].Z * v.Y + m[2].Z * v.Z + m[3].Z * v.W,
				m[0].W * v.X + m[1].W * v.Y + m[2].W * v.Z + m[3].W * v.W};
	}

	template<typename N, typename O>
	inline Vector<4, N> operator*(const Vector<4, O>& v, const Matrix<4, 4, N>& m)
	{
		return {v.X * m[0].X + v.Y * m[0].Y + v.Z * m[0].Z + v.W * m[0].W,
				v.X * m[1].X + v.Y * m[1].Y + v.Z * m[1].Z + v.W * m[1].W,
				v.X * m[2].X + v.Y * m[2].Y + v.Z * m[2].Z + v.W * m[2].W,
				v.X * m[3].X + v.Y * m[3].Y + v.Z * m[3].Z + v.W * m[3].W};
	}

	template<size_t R, typename N, typename O, $Scalar>
	inline Matrix<R, 4, N> operator+(O scalar, const Matrix<R, 4, N>& m)
	{
		return {scalar + m[0], scalar + m[1], scalar + m[2], scalar + m[3]};
	}

	template<size_t R, typename N, typename O, $Scalar>
	inline Matrix<R, 4, N> operator-(O scalar, const Matrix<R, 4, N>& m)
	{
		return {scalar - m[0], scalar - m[1], scalar - m[2], scalar - m[3]};
	}

	template<size_t R, typename N, typename O, $Scalar>
	inline Matrix<R, 4, N> operator*(O scalar, const Matrix<R, 4, N>& m)
	{
		return {scalar * m[0], scalar * m[1], scalar * m[2], scalar * m[3]};
	}

	template<size_t R, typename N, typename O, $Scalar>
	inline Matrix<R, 4, N> operator/(O scalar, const Matrix<R, 4, N>& m)
	{
		return {scalar / m[0], scalar / m[1], scalar / m[2], scalar / m[3]};
	}

	template<typename N> inline N Determinant(const Matrix<4, 4, N>& m)
	{
		N subFactor0 = m[2].Z * m[3].W - m[3].Z * m[2].W;
		N subFactor1 = m[2].Y * m[3].W - m[3].Y * m[2].W;
		N subFactor2 = m[2].Y * m[3].Z - m[3].Y * m[2].Z;
		N subFactor3 = m[2].X * m[3].W - m[3].X * m[2].W;
		N subFactor4 = m[2].X * m[3].Z - m[3].X * m[2].Z;
		N subFactor5 = m[2].X * m[3].Y - m[3].X * m[2].Y;

		N x = +(m[1].Y * subFactor0 - m[1].Z * subFactor1 + m[1].W * subFactor2);
		N y = -(m[1].X * subFactor0 - m[1].Z * subFactor3 + m[1].W * subFactor4);
		N z = +(m[1].X * subFactor1 - m[1].Y * subFactor3 + m[1].W * subFactor5);
		N w = -(m[1].X * subFactor2 - m[1].Y * subFactor4 + m[1].Z * subFactor5);

		auto coeffs = Vector<4, N>(x, y, z, w) * m[0];
		return coeffs.X + coeffs.Y + coeffs.Z + coeffs.W;
	}

	template<typename N, typename F = float>
	inline Matrix<4, 4, F> Inverse(const Matrix<4, 4, N>& m)
	{
		N coef00 = m[2].Z * m[3].W - m[3].Z * m[2].W;
		N coef02 = m[1].Z * m[3].W - m[3].Z * m[1].W;
		N coef03 = m[1].Z * m[2].W - m[2].Z * m[1].W;

		N coef04 = m[2].Y * m[3].W - m[3].Y * m[2].W;
		N coef06 = m[1].Y * m[3].W - m[3].Y * m[1].W;
		N coef07 = m[1].Y * m[2].W - m[2].Y * m[1].W;

		N coef08 = m[2].Y * m[3].Z - m[3].Y * m[2].Z;
		N coef10 = m[1].Y * m[3].Z - m[3].Y * m[1].Z;
		N coef11 = m[1].Y * m[2].Z - m[2].Y * m[1].Z;

		N coef12 = m[2].X * m[3].W - m[3].X * m[2].W;
		N coef14 = m[1].X * m[3].W - m[3].X * m[1].W;
		N coef15 = m[1].X * m[2].W - m[2].X * m[1].W;

		N coef16 = m[2].X * m[3].Z - m[3].X * m[2].Z;
		N coef18 = m[1].X * m[3].Z - m[3].X * m[1].Z;
		N coef19 = m[1].X * m[2].Z - m[2].X * m[1].Z;

		N coef20 = m[2].X * m[3].Y - m[3].X * m[2].Y;
		N coef22 = m[1].X * m[3].Y - m[3].X * m[1].Y;
		N coef23 = m[1].X * m[2].Y - m[2].X * m[1].Y;

		Vector<4, N> fac0(coef00, coef00, coef02, coef03);
		Vector<4, N> fac1(coef04, coef04, coef06, coef07);
		Vector<4, N> fac2(coef08, coef08, coef10, coef11);
		Vector<4, N> fac3(coef12, coef12, coef14, coef15);
		Vector<4, N> fac4(coef16, coef16, coef18, coef19);
		Vector<4, N> fac5(coef20, coef20, coef22, coef23);

		Vector<4, N> vec0(m[1].X, m[0].X, m[0].X, m[0].X);
		Vector<4, N> vec1(m[1].Y, m[0].Y, m[0].Y, m[0].Y);
		Vector<4, N> vec2(m[1].Z, m[0].Z, m[0].Z, m[0].Z);
		Vector<4, N> vec3(m[1].W, m[0].W, m[0].W, m[0].W);

		Vector<4, N> inv0(vec1 * fac0 - vec2 * fac1 + vec3 * fac2);
		Vector<4, N> inv1(vec0 * fac0 - vec2 * fac3 + vec3 * fac4);
		Vector<4, N> inv2(vec0 * fac1 - vec1 * fac3 + vec3 * fac5);
		Vector<4, N> inv3(vec0 * fac2 - vec1 * fac4 + vec2 * fac5);

		Vector<4, N> signA(+1, -1, +1, -1);
		Vector<4, N> signB(-1, +1, -1, +1);
		Matrix<4, 4, F> inverse(inv0 * signA, inv1 * signB, inv2 * signA, inv3 * signB);
		Vector<4, N> row(inverse[0].X, inverse[1].X, inverse[2].X, inverse[3].X);
		Vector<4, N> dot(m[0] * row);
		N dotProduct = dot.X + dot.Y + dot.Z + dot.W;
		return inverse * (static_cast<F>(1) / dotProduct);
	}

	template<typename N> inline Matrix<4, 2, N> Transpose(const Matrix<2, 4, N>& m)
	{
		return {m[0].X, m[1].X, m[2].X, m[3].X,
				m[0].Y, m[1].Y, m[2].Y, m[3].Y};
	}

	template<typename N> inline Matrix<4, 3, N> Transpose(const Matrix<3, 4, N>& m)
	{
		return {m[0].X, m[1].X, m[2].X, m[3].X,
				m[0].Y, m[1].Y, m[2].Y, m[3].Y,
				m[0].Z, m[1].Z, m[2].Z, m[3].Z};
	}

	template<typename N> inline Matrix<4, 4, N> Transpose(const Matrix<4, 4, N>& m)
	{
		return {m[0].X, m[1].X, m[2].X, m[3].X,
				m[0].Y, m[1].Y, m[2].Y, m[3].Y,
				m[0].Z, m[1].Z, m[2].Z, m[3].Z,
				m[0].W, m[1].W, m[2].W, m[3].W};
	}
}
