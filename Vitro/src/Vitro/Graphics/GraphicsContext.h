#pragma once


namespace Vitro
{
	class Window; // Forward declaration to avoid circular include

	class GraphicsContext
	{
	public:
		static GraphicsContext* New(Window* window);

		virtual void Initialize() = 0;
		virtual void SwapBuffers() = 0;
	};
}
