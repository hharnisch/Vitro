#include "_pch.h"
#include "File.h"

namespace Vitro
{
	HeapArray<char> File::LoadBinary(const std::string& path)
	{
		FILE* file;
		fopen_s(&file, path.c_str(), "rb");
		AssertCritical(file, "File not found: " + filePath);

		fseek(file, 0, SEEK_END);
		size_t size = ftell(file);
		rewind(file);

		HeapArray<char> data(size);
		fread(data.Raw(), size, 1, file);
		fclose(file);
		return data;
	}
}
