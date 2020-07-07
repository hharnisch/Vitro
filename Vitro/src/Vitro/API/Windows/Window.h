#pragma once

#include "Vitro/Graphics/Window.h"

#include <Windows.h>

namespace Vitro::Windows
{
	class Window : public Vitro::Window
	{
	public:
		Window(int width, int height, const std::string& title);
		~Window() override;

		std::string GetTitle() const override;
		void SetTitle(const std::string& title) override;

		int GetWidth() const override;
		void SetWidth(int width) override;

		int GetHeight() const override;
		void SetHeight(int height) override;

		void Show() override;
		void Minimize() override;
		void PlatformUpdate() override;

	private:
		HWND WindowHandle;

	#if $OPENGL
		HDC DeviceContext;
		HGLRC OpenGLContext;
	#endif
	};
}
