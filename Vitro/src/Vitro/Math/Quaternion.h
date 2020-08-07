#pragma once

#include "Vitro/Math/Vector.h"
#include "Vitro/Utility/Assert.h"

namespace Vitro
{
	template<typename N = float> struct Quaternion
	{
		union
		{
			struct { N A, B, C, D; };
			struct { N W, X, Y, Z; };
			N Val[4];
		};

		inline Quaternion() = default;

		template<typename O0, typename O1, typename O2, typename O3>
		inline Quaternion(O0 a, O1 b, O2 c, O3 d) : Val{static_cast<N>(a), static_cast<N>(b),
														static_cast<N>(c), static_cast<N>(d)}
		{}

		inline Quaternion(const Vector<3, N>& eulerAngles)
		{
			Vector<3, N> cos = Cos(eulerAngles * 0.5);
			Vector<3, N> sin = Sin(eulerAngles * 0.5);
			A = cos.X * cos.Y * cos.Z + sin.X * sin.Y * sin.Z;
			B = sin.X * cos.Y * cos.Z - cos.X * sin.Y * sin.Z;
			C = cos.X * sin.Y * cos.Z + sin.X * cos.Y * sin.Z;
			D = cos.X * cos.Y * sin.Z - sin.X * sin.Y * cos.Z;
		}

		inline N& operator[](size_t index)
		{
			AssertArrayRange(Val, index, "Quaternion");
			return Val[index];
		}

		inline const N& operator[](size_t index) const
		{
			AssertArrayRange(Val, index, "Quaternion");
			return Val[index];
		}

		template<typename O> inline Quaternion<N> operator+(const Quaternion<O>& q) const
		{
			return {A + q.A, B + q.B, C + q.C, D + q.D};
		}

		template<typename O> inline Quaternion<N> operator-(const Quaternion<O>& q) const
		{
			return {A - q.A, B - q.B, C - q.C, D - q.D};
		}

		template<typename O> inline Quaternion<N> operator*(const Quaternion<O>& q) const
		{
			return {A * q.A - B * q.B - C * q.C - D * q.D, A * q.B + B * q.A + C * q.D - D * q.C,
					A * q.C + C * q.A + D * q.B - B * q.D, A * q.D + D * q.A + B * q.C - C * q.B};
		}

		template<typename O> inline Quaternion<N>& operator+=(const Quaternion<O>& q)
		{
			A += q.A; B += q.B; C += q.C; D += q.D; return *this;
		}

		template<typename O> inline Quaternion<N>& operator-=(const Quaternion<O>& q)
		{
			A -= q.A; B -= q.B; C -= q.C; D -= q.D; return *this;
		}

		template<typename O> inline Quaternion<N>& operator*=(const Quaternion<O>& q)
		{
			return *this = *this * q;
		}

		template<typename O> inline bool operator==(const Quaternion<O>& q) const
		{
			return A == q.A && B == q.B && C == q.C && D == q.D;
		}

		template<typename O> inline bool operator!=(const Quaternion<O>& q) const
		{
			return A != q.A || B != q.B || C != q.C || D != q.D;
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Quaternion<N> operator+(O scalar) const
		{
			return {A + scalar, B + scalar, C + scalar, D + scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Quaternion<N> operator-(O scalar) const
		{
			return {A - scalar, B - scalar, C - scalar, D - scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Quaternion<N> operator*(O scalar) const
		{
			return {A * scalar, B * scalar, C * scalar, D * scalar};
		}

		template<typename O, VTR_IS_SCALAR(O)> inline Quaternion<N> operator/(O scalar) const
		{
			return {A / scalar, B / scalar, C / scalar, D / scalar};
		}

		template<typename O> inline Vector<3, N> operator*(const Vector<3, O>& v) const
		{
			Vector<3, N> qv(A, B, C);
			Vector<3, N> uv(Cross(qv, v));
			Vector<3, N> uuv(Cross(qv, uv));
			return v + (uv * D + uuv) * 2;
		}

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << "(" << +A << ", " << +B << ", " << +C << ", " << +D << ")";
			return s.str();
		}
	};

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Quaternion<N> operator+(O scalar, const Quaternion<N>& q)
	{
		return {scalar + q.A, scalar + q.B, scalar + q.C, scalar + q.D};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Quaternion<N> operator-(O scalar, const Quaternion<N>& q)
	{
		return {scalar - q.A, scalar - q.B, scalar - q.C, scalar - q.D};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Quaternion<N> operator*(O scalar, const Quaternion<N>& q)
	{
		return {scalar * q.A, scalar * q.B, scalar * q.C, scalar * q.D};
	}

	template<typename N, typename O, VTR_IS_SCALAR(O)>
	inline Quaternion<N> operator/(O scalar, const Quaternion<N>& q)
	{
		return {scalar / q.A, scalar / q.B, scalar / q.C, scalar / q.D};
	}
}
