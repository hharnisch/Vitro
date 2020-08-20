#pragma once

#include "Vitro/Graphics/Overlay.h"

namespace Vitro
{
	class UIOverlay final : public Overlay
	{
	public:
		UIOverlay() = default;
		~UIOverlay() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnTick(Tick t) override;
		void OnEvent(Event& event) override;
	};
}
