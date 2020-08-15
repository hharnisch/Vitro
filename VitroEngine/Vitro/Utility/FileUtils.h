#pragma once

#include "Vitro/Utility/HeapArray.h"

namespace Vitro
{
	class FileUtils
	{
	public:
		static HeapArray<char> GetBinaryData(const std::string& filePath);
		static std::string ToUpper(const std::string& str);
		static std::string& ModifyToUpper(std::string& str);

		FileUtils() = delete;
	};
}
