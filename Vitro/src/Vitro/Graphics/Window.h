#pragma once

#include "_pch.h"
#include "Vitro/Graphics/Layer.h"
#include "Vitro/Graphics/Overlay.h"

namespace Vitro
{
	class Window
	{
	public:
		virtual ~Window();

		static Window* New(int width, int height, int x, int y, const std::string& title);

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

		virtual void Open() = 0;
		virtual void Close() = 0;
		virtual void Maximize() = 0;
		virtual void Minimize() = 0;
		virtual void UpdatePlatform() = 0;

		uint64_t GetNativeID() const;

		void Update();
		void OnEvent(Event& e);
		void Detach(Layer& layer);
		void Detach(Overlay& overlay);

		template<class L, typename... Args>
		std::enable_if_t<std::is_base_of_v<Layer, L> && !std::is_base_of_v<Overlay, L>, L&>
			Attach(Args&... args)
		{
			return static_cast<L&>(*Attach(new L(args...)));
		}

		template<class O, typename... Args>
		std::enable_if_t<std::is_base_of_v<Overlay, O>, O&> Attach(Args&... args)
		{
			return static_cast<O&>(*Attach(new O(args...)));
		}

	protected:
		uint64_t NativeID = 0;

	private:
		std::vector<Layer*> LayerStack;
		unsigned int LastLayerIndex = 0;

		Layer* Attach(Layer* layer);
		Overlay* Attach(Overlay* overlay);
	};
}
