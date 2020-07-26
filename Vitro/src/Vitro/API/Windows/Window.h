#pragma once

#include "Vitro/Graphics/Window.h"

#include <Windows.h>

namespace Vitro::Windows
{
	class Window : public Vitro::Window
	{
	public:
		Window(int width, int height, int x, int y, const std::string& title);
		~Window() override;

		int GetWidth() const override;
		void SetWidth(int width) override;
		int GetHeight() const override;
		void SetHeight(int height) override;
		int GetX() const override;
		void SetX(int x) override;
		int GetY() const override;
		void SetY(int y) override;
		std::string GetTitle() const override;
		void SetTitle(const std::string& title) override;

		void Open() override;
		void Close() override;
		void Maximize() override;
		void Minimize() override;
		void UpdatePlatform() override;
		void OnPlatformEvent(Event& e) override;

	private:
		int Width;
		int Height;
		int X;
		int Y;
		std::string Title;
		HWND NativeHandle = nullptr;
	};
}
