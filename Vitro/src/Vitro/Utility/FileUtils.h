#pragma once

#include "Vitro/Utility/Array.h"

namespace Vitro
{
	class FileUtils
	{
	public:
		static Array<char> GetBinaryData(const std::string& filePath);

	private:
		FileUtils() = delete;
	};
}
