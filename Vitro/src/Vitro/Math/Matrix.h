#pragma once

#include <glm/matrix.hpp>
#include <glm/gtx/string_cast.hpp>

namespace Vitro
{
	template<typename... Args> std::string Str(Args&&... args)
	{
		return glm::to_string(std::forward<Args>(args)...);
	}

	typedef glm::mat2						Matrix2;
	typedef glm::mat2x3						Matrix2x3;
	typedef glm::mat2x4						Matrix2x4;
	typedef glm::mat3x2						Matrix3x2;
	typedef glm::mat3						Matrix3;
	typedef glm::mat3x4						Matrix3x4;
	typedef glm::mat4x2						Matrix4x2;
	typedef glm::mat4x3						Matrix4x3;
	typedef glm::mat4						Matrix4;

	typedef glm::mat<2, 2, signed char>		SByte2x2;
	typedef glm::mat<2, 3, signed char>		SByte2x3;
	typedef glm::mat<2, 4, signed char>		SByte2x4;
	typedef glm::mat<3, 2, signed char>		SByte3x2;
	typedef glm::mat<3, 3, signed char>		SByte3x3;
	typedef glm::mat<3, 4, signed char>		SByte3x4;
	typedef glm::mat<4, 2, signed char>		SByte4x2;
	typedef glm::mat<4, 3, signed char>		SByte4x3;
	typedef glm::mat<4, 4, signed char>		SByte4x4;
	typedef glm::mat<2, 2, unsigned char>	Byte2x2;
	typedef glm::mat<2, 3, unsigned char>	Byte2x3;
	typedef glm::mat<2, 4, unsigned char>	Byte2x4;
	typedef glm::mat<3, 2, unsigned char>	Byte3x2;
	typedef glm::mat<3, 3, unsigned char>	Byte3x3;
	typedef glm::mat<3, 4, unsigned char>	Byte3x4;
	typedef glm::mat<4, 2, unsigned char>	Byte4x2;
	typedef glm::mat<4, 3, unsigned char>	Byte4x3;
	typedef glm::mat<4, 4, unsigned char>	Byte4x4;
	typedef glm::mat<2, 2, short>			Short2x2;
	typedef glm::mat<2, 3, short>			Short2x3;
	typedef glm::mat<2, 4, short>			Short2x4;
	typedef glm::mat<3, 2, short>			Short3x2;
	typedef glm::mat<3, 3, short>			Short3x3;
	typedef glm::mat<3, 4, short>			Short3x4;
	typedef glm::mat<4, 2, short>			Short4x2;
	typedef glm::mat<4, 3, short>			Short4x3;
	typedef glm::mat<4, 4, short>			Short4x4;
	typedef glm::mat<2, 2, unsigned short>	UShort2x2;
	typedef glm::mat<2, 3, unsigned short>	UShort2x3;
	typedef glm::mat<2, 4, unsigned short>	UShort2x4;
	typedef glm::mat<3, 2, unsigned short>	UShort3x2;
	typedef glm::mat<3, 3, unsigned short>	UShort3x3;
	typedef glm::mat<3, 4, unsigned short>	UShort3x4;
	typedef glm::mat<4, 2, unsigned short>	UShort4x2;
	typedef glm::mat<4, 3, unsigned short>	UShort4x3;
	typedef glm::mat<4, 4, unsigned short>	UShort4x4;
	typedef glm::mat<2, 2, int>				Int2x2;
	typedef glm::mat<2, 3, int>				Int2x3;
	typedef glm::mat<2, 4, int>				Int2x4;
	typedef glm::mat<3, 2, int>				Int3x2;
	typedef glm::mat<3, 3, int>				Int3x3;
	typedef glm::mat<3, 4, int>				Int3x4;
	typedef glm::mat<4, 2, int>				Int4x2;
	typedef glm::mat<4, 3, int>				Int4x3;
	typedef glm::mat<4, 4, int>				Int4x4;
	typedef glm::mat<2, 2, unsigned int>	UInt2x2;
	typedef glm::mat<2, 3, unsigned int>	UInt2x3;
	typedef glm::mat<2, 4, unsigned int>	UInt2x4;
	typedef glm::mat<3, 2, unsigned int>	UInt3x2;
	typedef glm::mat<3, 3, unsigned int>	UInt3x3;
	typedef glm::mat<3, 4, unsigned int>	UInt3x4;
	typedef glm::mat<4, 2, unsigned int>	UInt4x2;
	typedef glm::mat<4, 3, unsigned int>	UInt4x3;
	typedef glm::mat<4, 4, unsigned int>	UInt4x4;
	typedef glm::mat<2, 2, long>			Long2x2;
	typedef glm::mat<2, 3, long>			Long2x3;
	typedef glm::mat<2, 4, long>			Long2x4;
	typedef glm::mat<3, 2, long>			Long3x2;
	typedef glm::mat<3, 3, long>			Long3x3;
	typedef glm::mat<3, 4, long>			Long3x4;
	typedef glm::mat<4, 2, long>			Long4x2;
	typedef glm::mat<4, 3, long>			Long4x3;
	typedef glm::mat<4, 4, long>			Long4x4;
	typedef glm::mat<2, 2, unsigned long>	ULong2x2;
	typedef glm::mat<2, 3, unsigned long>	ULong2x3;
	typedef glm::mat<2, 4, unsigned long>	ULong2x4;
	typedef glm::mat<3, 2, unsigned long>	ULong3x2;
	typedef glm::mat<3, 3, unsigned long>	ULong3x3;
	typedef glm::mat<3, 4, unsigned long>	ULong3x4;
	typedef glm::mat<4, 2, unsigned long>	ULong4x2;
	typedef glm::mat<4, 3, unsigned long>	ULong4x3;
	typedef glm::mat<4, 4, unsigned long>	ULong4x4;
	typedef glm::mat<2, 2, float>			Float2x2;
	typedef glm::mat<2, 3, float>			Float2x3;
	typedef glm::mat<2, 4, float>			Float2x4;
	typedef glm::mat<3, 2, float>			Float3x2;
	typedef glm::mat<3, 3, float>			Float3x3;
	typedef glm::mat<3, 4, float>			Float3x4;
	typedef glm::mat<4, 2, float>			Float4x2;
	typedef glm::mat<4, 3, float>			Float4x3;
	typedef glm::mat<4, 4, float>			Float4x4;
	typedef glm::mat<2, 2, double>			Double2x2;
	typedef glm::mat<2, 3, double>			Double2x3;
	typedef glm::mat<2, 4, double>			Double2x4;
	typedef glm::mat<3, 2, double>			Double3x2;
	typedef glm::mat<3, 3, double>			Double3x3;
	typedef glm::mat<3, 4, double>			Double3x4;
	typedef glm::mat<4, 2, double>			Double4x2;
	typedef glm::mat<4, 3, double>			Double4x3;
	typedef glm::mat<4, 4, double>			Double4x4;
}
