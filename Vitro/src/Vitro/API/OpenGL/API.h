#pragma once

namespace Vitro::OpenGL
{
	class API
	{
	public:
		static void Initialize();

	private:
		static bool IsInitialized;

		static void InitializeWindows();

		API() = delete;
	};
}
