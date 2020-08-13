#include "_pch.h"
#include "Camera.h"

namespace Vitro
{
	Camera::Camera(const Float3& position, const Float4x4& projection) :
		Position(position), Projection(projection), Orientation(0, 0, 0)
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

	const Float3& Camera::GetOrientation() const
	{
		return Orientation;
	}

	void Camera::SetOrientation(const Float3& orientation)
	{
		Orientation = orientation;
		UpdateView();
	}

	void Camera::AdjustOrientation(const Float3& orientation)
	{
		Orientation += orientation;
		UpdateView();
	}

	void Camera::UpdateView()
	{
		View = LookAtLH(Position, Orientation, DefaultUp);
	}
}
