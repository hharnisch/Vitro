#pragma once

#include "_pch.h"
#include "Vitro/Events/Window/WindowCloseEvent.h"
#include "Vitro/Graphics/Layer.h"
#include "Vitro/Graphics/Overlay.h"

namespace Vitro
{
	class Window
	{
	public:
		virtual ~Window() = default;

		static Window* New(int width, int height, int x, int y, const std::string& title);

		virtual std::string GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;

		virtual int GetWidth() const = 0;
		virtual void SetWidth(int width) = 0;

		virtual int GetHeight() const = 0;
		virtual void SetHeight(int height) = 0;

		virtual int GetX() const = 0;
		virtual void SetX(int x) = 0;

		virtual int GetY() const = 0;
		virtual void SetY(int y) = 0;

		virtual void Show() = 0;
		virtual void Minimize() = 0;

		virtual void PrepareUpdate() = 0;
		virtual void FinalizeUpdate() = 0;

		void Attach(Layer* layer);
		void Attach(Overlay* overlay);

		void Detach(Layer* layer);
		void Detach(Overlay* overlay);

		void Update();
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);

	protected:
		uint64_t NativeID = 0;

	private:
		std::vector<Layer*> LayerStack;
		unsigned int LastLayerIndex = 0;
	};
}
