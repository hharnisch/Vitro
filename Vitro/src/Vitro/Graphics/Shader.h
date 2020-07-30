#pragma once

#include "_pch.h"
#include "Vitro/Math/Matrix.h"
#include "Vitro/Math/Vector.h"
#include "Vitro/Utility/Array.h"

namespace Vitro
{
	class Shader
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, const Array<int>& arr) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat3(const std::string& name, const Vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const Vec4& value) = 0;
		virtual void SetMat4(const std::string& name, const Mat4& value) = 0;
	};
}
