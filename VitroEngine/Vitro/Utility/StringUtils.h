#pragma once

namespace Vitro
{
	static inline std::string ToUpper(const std::string& str)
	{
		std::string newstr(str.size(), 0);
		for(int i = 0; i < str.size(); i++)
			newstr[i] = std::toupper(str[i]);
		return newstr;
	}

	static inline std::string& ModifyToUpper(std::string& str)
	{
		for(char& ch : str)
			ch = std::toupper(ch);
		return str;
	}
}