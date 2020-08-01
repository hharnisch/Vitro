#pragma once

#include "Vitro/Utility/Array.h"

namespace Vitro
{
	class FileUtils
	{
	public:
		static Array<char> GetBinaryData(const std::string& filePath);
		static std::string ToUpper(const std::string& str);
		static std::string& ModifyToUpper(std::string& str);

	private:
		FileUtils() = delete;
	};
}
