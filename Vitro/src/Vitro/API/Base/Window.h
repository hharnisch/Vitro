#pragma once

#include "_pch.h"
#include "Vitro/Events/Event.h"
#include "Vitro/Graphics/Layer.h"
#include "Vitro/Graphics/Overlay.h"

namespace Vitro::Base
{
	class Window
	{
	public:
		virtual int GetWidth() const = 0;
		virtual void SetWidth(int width) = 0;
		virtual int GetHeight() const = 0;
		virtual void SetHeight(int height) = 0;
		virtual int GetX() const = 0;
		virtual void SetX(int x) = 0;
		virtual int GetY() const = 0;
		virtual void SetY(int y) = 0;
		virtual std::string GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual void* GetNativeHandle() const = 0;
		virtual void Open() = 0;
		virtual void Close() = 0;
		virtual void Maximize() = 0;
		virtual void Minimize() = 0;
		virtual void PollEvents() = 0;
		virtual void PlatformOnEvent(Event& e) = 0;

		void Update();
		void OnEvent(Event& e);
		void Detach(Layer& layer);
		void Detach(Overlay& overlay);

		template<typename L, typename... Args>
		std::enable_if_t<std::is_base_of_v<Layer, L> && !std::is_base_of_v<Overlay, L>, L&>
			Attach(Args&... args)
		{
			return static_cast<L&>(Attach(*new L(std::forward<Args>(args)...)));
		}

		template<typename O, typename... Args>
		std::enable_if_t<std::is_base_of_v<Overlay, O>, O&> Attach(Args&... args)
		{
			return static_cast<O&>(Attach(*new O(std::forward<Args>(args)...)));
		}

	protected:
		std::shared_ptr<Renderer3D> Renderer = nullptr;

		Window() = default;
		Window(int width, int height, int x, int y, const std::string& title);
		Window(Window&& other) noexcept;
		virtual ~Window();
		Window& operator=(Window&& other) noexcept;

	private:
		std::vector<Layer*> LayerStack;
		unsigned int LastLayerIndex = 0;

		Layer& Attach(Layer& layer);
		Overlay& Attach(Overlay& overlay);

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
	};
}
