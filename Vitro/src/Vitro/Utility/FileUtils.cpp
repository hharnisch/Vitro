#include "_pch.h"
#include "FileUtils.h"

#include "Vitro/Utility/Assert.h"

namespace Vitro
{
	Array<char> FileUtils::GetBinaryData(const std::string& filePath)
	{
		FILE* file;
		fopen_s(&file, filePath.c_str(), "rb");
		Assert(file, "File not found: " + filePath);
		fseek(file, 0, SEEK_END);

		size_t size;
		size = ftell(file);
		rewind(file);

		Array<char> data(size);
		fread(data.Data, size, 1, file);
		fclose(file);
		return data;
	}
}
