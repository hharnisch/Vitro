#include "_pch.h"
#include "Camera.h"

namespace Vitro
{
	Camera::Camera(const Float3& position, const Float4x4& projection) :
		Position(position), Projection(projection)
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

	void Camera::Translate(const Float3& translation)
	{
		Position += Right * translation.X;
		Position += Up * translation.Y;
		Position += Forward * translation.Z;
		UpdateView();
	}

	void Camera::Pitch(float radians)
	{
		Forward = Normalize(Forward * std::cos(radians) + Up * std::sin(radians));
		Up = Cross(Forward, Right);
		UpdateView();
	}

	void Camera::Yaw(float radians)
	{
		Forward = Normalize(Forward * std::cos(radians) + Right * std::sin(radians));
		Right = Cross(Up, Forward);
		UpdateView();
	}

	void Camera::Roll(float radians)
	{
		Right = Normalize(Right * std::cos(radians) + Up * std::sin(radians));
		Up = Cross(Forward, Right);
		UpdateView();
	}

	void Camera::UpdateView()
	{
		View = LookAt(Position, Position + Forward, Up);
	}
}
