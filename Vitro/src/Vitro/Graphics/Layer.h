#pragma once

#include "Vitro/Events/Event.h"

namespace Vitro
{
	class Layer
	{
	public:
		bool Active = true;

		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;

		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& e) = 0;
	};
}
