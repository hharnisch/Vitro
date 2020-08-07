#include "_pch.h"
#include "Camera.h"

namespace Vitro
{
	Camera::Camera(const Float4x4& projection) :
		Projection(projection), Position(0), Rotation(90, 0, 0), FocalPoint(0)
	{}
}
