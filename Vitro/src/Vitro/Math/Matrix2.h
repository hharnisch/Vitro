#pragma once

#include "Vitro/Math/Vector2.h"

namespace Vitro
{
	template<size_t R, size_t C, typename N> struct Matrix;

	template<typename N> struct Matrix<2, 2, N>
	{
	private:
		typedef Vector<2, N> Col;
		Col Columns[2];

	public:
		inline Matrix() = default;

		template<typename O0, typename O1, typename O2, typename O3>
		inline Matrix(O0 x0, O1 y0, O2 x1, O3 y1) : Columns{Col(x0, y0), Col(x1, y1)} {}

		template<typename O>
		inline Matrix(O scalar) : Columns{Col(scalar), Col(scalar)} {}

		template<typename O0, typename O1>
		inline Matrix(const Vector<2, O0>& v0, const Vector<2, O1>& v1) : Columns{v0, v1} {}

		inline Col& operator[](size_t index)
		{
			if(index < sizeof(Columns) / sizeof(*Columns))
				return Columns[index];
			else
				throw std::out_of_range("Matrix column index out of range.");
		}

		template<typename O>
		inline Matrix(const Matrix<2, 2, O>& other) : Columns{other[0], other[1]} {} //TODO

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << "[" << static_cast<std::string>(Columns[0]) << ", ";
			s << static_cast<std::string>(Columns[1]) << "]";
			return s.str();
		}
	};
}
