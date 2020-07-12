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
		inline Matrix(N scalar) : Columns{Col(scalar), Col(scalar)} {}
		inline Matrix(N x0, N y0, N x1, N y1) : Columns{Col(x0, y0), Col(x1, y1)} {}
		inline Matrix(const Col& x, const Col& y) : Columns{x, y} {}

		template<typename O> inline Matrix(O scalar) : Matrix(static_cast<N>(scalar)) {}

		template<typename O1, typename O2, typename O3, typename O4>
		inline Matrix(O1 x0, O2 y0, O3 x1, O4 y1)
			: Matrix(static_cast<N>(x0), static_cast<N>(y0),
					 static_cast<N>(x1), static_cast<N>(y1))
		{}

		inline Col& operator[](size_t index)
		{
			if(index < sizeof(Columns) / sizeof(*Columns))
				return Columns[index];
			else
				throw std::out_of_range("Matrix column index out of range.");
		}

		inline explicit operator std::string() const
		{
			std::stringstream s;
			s << "[" << static_cast<std::string>(Columns[0]) << ", ";
			s << static_cast<std::string>(Columns[1]) << "]";
			return s.str();
		}
	};
}
