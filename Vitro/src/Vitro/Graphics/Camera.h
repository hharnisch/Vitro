#pragma once

#include "Vitro/Math/Matrix.h"
#include "Vitro/Math/Quaternion.h"

namespace Vitro
{
	class Camera
	{
	public:
		Camera(const Float4x4& projection);

	private:
		Float4x4 Projection, View, ViewProjection;
		Float3 Position, Rotation, FocalPoint;
		Quaternion<> Orientation;
		float Distance;
	};
}
