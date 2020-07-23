#pragma once

namespace Vitro::OpenGL
{
	class API
	{
	public:
		static void Initialize();

	private:
		static void InitializeWindows();

		API() = delete;
	};
}
