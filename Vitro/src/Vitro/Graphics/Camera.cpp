#include "_pch.h"
#include "Camera.h"

namespace Vitro
{
	Camera::Camera(const Float4x4& projection) :
		Projection(projection), Position(0), Orientation(1, 0, 0, 0)
	{
		UpdateView();
	}

	const Float4x4& Camera::GetView() const
	{
		return View;
	}

	const Float4x4& Camera::GetProjection() const
	{
		return Projection;
	}

	const Float3& Camera::GetPosition() const
	{
		return Position;
	}

	void Camera::SetPosition(const Float3& position)
	{
		Position = position;
		UpdateView();
	}

	void Camera::AdjustPosition(const Float3& position)
	{
		Position += position;
		UpdateView();
	}

	const Quaternion<>& Camera::GetOrientation() const
	{
		return Orientation;
	}

	void Camera::SetOrientation(const Quaternion<>& orientation)
	{
		Orientation = orientation;
		UpdateView();
	}

	void Camera::SetOrientation(const Float3& eulerAngles)
	{
		Orientation = Quaternion(eulerAngles);
		UpdateView();
	}

	void Camera::UpdateView()
	{
		View = Inverse(Translate(Float4x4::Identity(), Position) * Float4x4(Orientation));
	}
}
