#pragma once

#include "Vitro/Graphics/Overlay.h"

namespace Vitro
{
	class UIOverlay : public Overlay
	{
	public:
		UIOverlay() = default;
		~UIOverlay() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	};
}
