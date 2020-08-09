#pragma once

#include "Vitro/Math/Matrix.h"
#include "Vitro/Math/Quaternion.h"

namespace Vitro
{
	class Camera
	{
	public:
		Camera(const Float4x4& projection);

		const Float4x4& GetView() const;
		const Float4x4& GetProjection() const;

		const Float3& GetPosition() const;
		void SetPosition(const Float3& position);
		void AdjustPosition(const Float3& position);
		const Quaternion<>& GetOrientation() const;
		void SetOrientation(const Quaternion<>& rotation);
		void SetOrientation(const Float3& eulerAngles);

	private:
		static constexpr Float3 DefaultForward{0, 0, 1};
		static constexpr Float3 DefaultRight{1, 0, 0};
		static constexpr Float3 DefaultUp{0, 1, 0};

		Float4x4 Projection, View;
		Float3 Position;
		Quaternion<> Orientation;

		void UpdateView();
	};
}
