#pragma once

namespace Vitro
{
	class UI
	{
	public:
		static void Initialize();
		static void Finalize();

	private:
		UI() = delete;
	};
}
