#pragma once

#include "Vitro/Utility/HeapArray.h"

namespace Vitro
{
	HeapArray<char> GetBinaryFileData(const std::string& filePath);
	HeapArray<char> GetTGAImageData(const std::string& filePath, uint32_t& width, uint32_t& height);
	std::string StringToUpper(const std::string& str);
	std::string& ModifyStringToUpper(std::string& str);
}
