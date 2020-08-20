#pragma once

#include "Vitro/Utility/HeapArray.h"

namespace Vitro
{
	HeapArray<char> GetBinaryFileData(const std::string& filePath);
	std::string StringToUpper(const std::string& str);
	std::string& ModifyStringToUpper(std::string& str);
}
