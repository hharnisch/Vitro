#pragma once

#include "Vitro/Utility/HeapArray.h"

namespace Vitro
{
	class File final
	{
	public:
		static HeapArray<char> LoadBinary(const std::string& path);

		File() = delete;
	};
}
