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

	HeapArray<char> GetTGAImageData(const std::string& filePath, uint32_t& width, uint32_t& height)
	{
		FILE* file;
		fopen_s(&file, filePath.c_str(), "rb");
		AssertCritical(file, "File not found: " + filePath);

		struct TGAHeader
		{
			unsigned char Data1[12];
			unsigned short Width;
			unsigned short Height;
			unsigned char BitsPerPixel;
			unsigned char Data2;
		} header;
		fread(&header, sizeof(TGAHeader), 1, file);
		AssertCritical(header.BitsPerPixel == 32, "TGA file should have 32-bit pixel depth.");

		width = static_cast<uint32_t>(header.Width);
		height = static_cast<uint32_t>(header.Height);

		size_t imageSize = 4LL * width * height;
		HeapArray<char> image(imageSize);
		size_t count = fread(image.Raw(), 1, imageSize, file);
		fclose(file);
		AssertCritical(count == imageSize, "TGA header shows false image size.");

		return image;
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
