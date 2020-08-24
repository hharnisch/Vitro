#pragma once

#include "Vitro/Application/Event.h"
#include "Vitro/Graphics/Renderer3D.h"
#include "Vitro/Utility/Ref.h"
#include "Vitro/Utility/Tick.h"

namespace Vitro
{
	class Layer
	{
	public:
		Ref<Renderer3D> Renderer;
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