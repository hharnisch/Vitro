#include "_pch.h"
#include "FileUtils.h"

namespace Vitro
{
	HeapArray<char> GetBinaryFileData(const std::string& filePath)
	{
		FILE* file;
		fopen_s(&file, filePath.c_str(), "rb");
		AssertCritical(file, "File not found: " + filePath);
		fseek(file, 0, SEEK_END);

		size_t size;
		size = ftell(file);
		rewind(file);

		HeapArray<char> data(size);
		fread(data.Raw(), size, 1, file);
		fclose(file);
		return data;
	}

	std::string StringToUpper(const std::string& str)
	{
		std::string newstr(str.size(), 0);
		for(int i = 0; i < str.size(); i++)
			newstr[i] = std::toupper(str[i]);
		return newstr;
	}

	std::string& ModifyStringToUpper(std::string& str)
	{
		for(char& ch : str)
			ch = std::toupper(ch);
		return str;
	}
}
