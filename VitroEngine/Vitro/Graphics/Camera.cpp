#include "_pch.h"
#include "Camera.h"

#include "Vitro/Math/Trigonometry.h"
#include <Vitro\Utility\Log.h> // TODO

namespace Vitro
{
	Camera::Camera(const Float3& position, const Quaternion<>& orientation,
				   const Float4x4& projection) :
		Position(position), Orientation(orientation), Projection(projection)
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

	void Camera::Translate(const Float3& adjustment)
	{
		Position += adjustment;
		UpdateView();
	}

	const Quaternion<>& Camera::GetOrientation() const
	{
		return Orientation;
	}

	void Camera::SetOrientation(const Quaternion<>& orientation)
	{
		Orientation = Normalize(orientation);
		UpdateView();
	}

	void Camera::SetOrientation(const Float3& eulerAngles)
	{
		Orientation = Quaternion(eulerAngles);
		UpdateView();
	}

	void Camera::Rotate(float pitch, float yaw, float roll)
	{
		Orientation *= Quaternion({pitch, yaw, roll});
		UpdateView();
	}

	void Camera::UpdateView()
	{
		View = Inverse(Vitro::Translate(Position) * Float4x4(Orientation));
	}
}
