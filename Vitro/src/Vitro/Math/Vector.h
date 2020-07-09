#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/string_cast.hpp>

namespace Vitro
{
	template<typename... Args> std::string Str(Args&&... args)
	{
		return glm::to_string(std::forward<Args>(args)...);
	}

	typedef glm::vec2					Vector2;
	typedef glm::vec3					Vector3;
	typedef glm::vec4					Vector4;

	typedef glm::vec<2, signed char>	SByte2;
	typedef glm::vec<3, signed char>	SByte3;
	typedef glm::vec<4, signed char>	SByte4;
	typedef glm::vec<2, unsigned char>	Byte2;
	typedef glm::vec<3, unsigned char>	Byte3;
	typedef glm::vec<4, unsigned char>	Byte4;
	typedef glm::vec<2, short>			Short2;
	typedef glm::vec<3, short>			Short3;
	typedef glm::vec<4, short>			Short4;
	typedef glm::vec<2, unsigned short>	UShort2;
	typedef glm::vec<3, unsigned short>	UShort3;
	typedef glm::vec<4, unsigned short>	UShort4;
	typedef glm::vec<2, int>			Int2;
	typedef glm::vec<3, int>			Int3;
	typedef glm::vec<4, int>			Int4;
	typedef glm::vec<2, unsigned int>	UInt2;
	typedef glm::vec<3, unsigned int>	UInt3;
	typedef glm::vec<4, unsigned int>	UInt4;
	typedef glm::vec<2, long>			Long2;
	typedef glm::vec<3, long>			Long3;
	typedef glm::vec<4, long>			Long4;
	typedef glm::vec<2, unsigned long>	ULong2;
	typedef glm::vec<3, unsigned long>	ULong3;
	typedef glm::vec<4, unsigned long>	ULong4;
	typedef glm::vec<2, float>			Float2;
	typedef glm::vec<3, float>			Float3;
	typedef glm::vec<4, float>			Float4;
	typedef glm::vec<2, double>			Double2;
	typedef glm::vec<3, double>			Double3;
	typedef glm::vec<4, double>			Double4;
}
