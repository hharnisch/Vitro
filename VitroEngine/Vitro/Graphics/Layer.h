#pragma once

#include "Vitro/Events/Event.h"
#include "Vitro/Utility/Tick.h"

namespace Vitro
{
	class Renderer3D; // Forward declaration

	class Layer
	{
	public:
		std::shared_ptr<Renderer3D> Renderer;
		bool Enabled = true;

		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnTick(Tick t) = 0;
		virtual void OnEvent(Event& e) = 0;

		Layer(const Layer&) = delete;
		Layer(Layer&&) = delete;
		Layer& operator=(const Layer&) = delete;
		Layer& operator=(Layer&&) = delete;
	};
}
