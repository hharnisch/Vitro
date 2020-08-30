#pragma once

#include "Vitro/Application/Overlay.h"

namespace Vitro
{
	class Editor : public Overlay
	{
	public:
		void OnAttach() override;
		void OnDetach() override;
		void OnTick(Tick t) override;
		void OnEvent(Event& e) override;
	};
}
