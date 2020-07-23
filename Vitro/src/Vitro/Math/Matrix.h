﻿#pragma once

#include "Vitro/Math/Matrix2.h"
#include "Vitro/Math/Matrix3.h"
#include "Vitro/Math/Matrix4.h"

namespace Vitro
{
	typedef Matrix<2, 2, int8_t>		SByte2x2;
	typedef Matrix<2, 3, int8_t>		SByte2x3;
	typedef Matrix<2, 4, int8_t>		SByte2x4;
	typedef Matrix<3, 2, int8_t>		SByte3x2;
	typedef Matrix<3, 3, int8_t>		SByte3x3;
	typedef Matrix<3, 4, int8_t>		SByte3x4;
	typedef Matrix<4, 2, int8_t>		SByte4x2;
	typedef Matrix<4, 3, int8_t>		SByte4x3;
	typedef Matrix<4, 4, int8_t>		SByte4x4;
	typedef Matrix<2, 2, uint8_t>		Byte2x2;
	typedef Matrix<2, 3, uint8_t>		Byte2x3;
	typedef Matrix<2, 4, uint8_t>		Byte2x4;
	typedef Matrix<3, 2, uint8_t>		Byte3x2;
	typedef Matrix<3, 3, uint8_t>		Byte3x3;
	typedef Matrix<3, 4, uint8_t>		Byte3x4;
	typedef Matrix<4, 2, uint8_t>		Byte4x2;
	typedef Matrix<4, 3, uint8_t>		Byte4x3;
	typedef Matrix<4, 4, uint8_t>		Byte4x4;
	typedef Matrix<2, 2, int16_t>		Short2x2;
	typedef Matrix<2, 3, int16_t>		Short2x3;
	typedef Matrix<2, 4, int16_t>		Short2x4;
	typedef Matrix<3, 2, int16_t>		Short3x2;
	typedef Matrix<3, 3, int16_t>		Short3x3;
	typedef Matrix<3, 4, int16_t>		Short3x4;
	typedef Matrix<4, 2, int16_t>		Short4x2;
	typedef Matrix<4, 3, int16_t>		Short4x3;
	typedef Matrix<4, 4, int16_t>		Short4x4;
	typedef Matrix<2, 2, uint16_t>		UShort2x2;
	typedef Matrix<2, 3, uint16_t>		UShort2x3;
	typedef Matrix<2, 4, uint16_t>		UShort2x4;
	typedef Matrix<3, 2, uint16_t>		UShort3x2;
	typedef Matrix<3, 3, uint16_t>		UShort3x3;
	typedef Matrix<3, 4, uint16_t>		UShort3x4;
	typedef Matrix<4, 2, uint16_t>		UShort4x2;
	typedef Matrix<4, 3, uint16_t>		UShort4x3;
	typedef Matrix<4, 4, uint16_t>		UShort4x4;
	typedef Matrix<2, 2, int32_t>		Int2x2;
	typedef Matrix<2, 3, int32_t>		Int2x3;
	typedef Matrix<2, 4, int32_t>		Int2x4;
	typedef Matrix<3, 2, int32_t>		Int3x2;
	typedef Matrix<3, 3, int32_t>		Int3x3;
	typedef Matrix<3, 4, int32_t>		Int3x4;
	typedef Matrix<4, 2, int32_t>		Int4x2;
	typedef Matrix<4, 3, int32_t>		Int4x3;
	typedef Matrix<4, 4, int32_t>		Int4x4;
	typedef Matrix<2, 2, uint32_t>		UInt2x2;
	typedef Matrix<2, 3, uint32_t>		UInt2x3;
	typedef Matrix<2, 4, uint32_t>		UInt2x4;
	typedef Matrix<3, 2, uint32_t>		UInt3x2;
	typedef Matrix<3, 3, uint32_t>		UInt3x3;
	typedef Matrix<3, 4, uint32_t>		UInt3x4;
	typedef Matrix<4, 2, uint32_t>		UInt4x2;
	typedef Matrix<4, 3, uint32_t>		UInt4x3;
	typedef Matrix<4, 4, uint32_t>		UInt4x4;
	typedef Matrix<2, 2, int64_t>		Long2x2;
	typedef Matrix<2, 3, int64_t>		Long2x3;
	typedef Matrix<2, 4, int64_t>		Long2x4;
	typedef Matrix<3, 2, int64_t>		Long3x2;
	typedef Matrix<3, 3, int64_t>		Long3x3;
	typedef Matrix<3, 4, int64_t>		Long3x4;
	typedef Matrix<4, 2, int64_t>		Long4x2;
	typedef Matrix<4, 3, int64_t>		Long4x3;
	typedef Matrix<4, 4, int64_t>		Long4x4;
	typedef Matrix<2, 2, uint64_t>		ULong2x2;
	typedef Matrix<2, 3, uint64_t>		ULong2x3;
	typedef Matrix<2, 4, uint64_t>		ULong2x4;
	typedef Matrix<3, 2, uint64_t>		ULong3x2;
	typedef Matrix<3, 3, uint64_t>		ULong3x3;
	typedef Matrix<3, 4, uint64_t>		ULong3x4;
	typedef Matrix<4, 2, uint64_t>		ULong4x2;
	typedef Matrix<4, 3, uint64_t>		ULong4x3;
	typedef Matrix<4, 4, uint64_t>		ULong4x4;
	typedef Matrix<2, 2, float>			Float2x2, Mat2;
	typedef Matrix<2, 3, float>			Float2x3, Mat2x3;
	typedef Matrix<2, 4, float>			Float2x4, Mat2x4;
	typedef Matrix<3, 2, float>			Float3x2, Mat3x2;
	typedef Matrix<3, 3, float>			Float3x3, Mat3;
	typedef Matrix<3, 4, float>			Float3x4, Mat3x4;
	typedef Matrix<4, 2, float>			Float4x2, Mat4x2;
	typedef Matrix<4, 3, float>			Float4x3, Mat4x3;
	typedef Matrix<4, 4, float>			Float4x4, Mat4;
	typedef Matrix<2, 2, double>		Double2x2;
	typedef Matrix<2, 3, double>		Double2x3;
	typedef Matrix<2, 4, double>		Double2x4;
	typedef Matrix<3, 2, double>		Double3x2;
	typedef Matrix<3, 3, double>		Double3x3;
	typedef Matrix<3, 4, double>		Double3x4;
	typedef Matrix<4, 2, double>		Double4x2;
	typedef Matrix<4, 3, double>		Double4x3;
	typedef Matrix<4, 4, double>		Double4x4;
	typedef Matrix<2, 2, long double>	LDouble2x2;
	typedef Matrix<2, 3, long double>	LDouble2x3;
	typedef Matrix<2, 4, long double>	LDouble2x4;
	typedef Matrix<3, 2, long double>	LDouble3x2;
	typedef Matrix<3, 3, long double>	LDouble3x3;
	typedef Matrix<3, 4, long double>	LDouble3x4;
	typedef Matrix<4, 2, long double>	LDouble4x2;
	typedef Matrix<4, 3, long double>	LDouble4x3;
	typedef Matrix<4, 4, long double>	LDouble4x4;
}
