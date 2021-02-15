#include <Windows.h>
#include <string>
#include <regex>
#include <iostream>
/*
  Using namespace std is retarded as fuck :|
*/


void replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos != std::string::npos) 
	str.replace(start_pos, from.length(), to);
}

namespace Parser {

	/*
	 Whould parse whole to find the EQ
	*/
	std::string ParseWhole(std::string Script) {
		size_t Found = Script.find("break;");
		if (Found != std::string::npos) {
			char arr[] = "break;";
			Found = Script.find(arr, Found + 3);
			if (Found != std::string::npos) {
				size_t EQIndexVar = 0;
				for (int i = 1; i < 100; i++) {
					if (Script.at(Found - i) == (char) "=" && Script.at(Found - (i - 1)) != (char)"d") {
						EQIndexVar = Found - 1;
						break;
					}
				}

				std::regex Variable("= (.*?);");

				replace(Script, Script.substr(1, EQIndexVar - 1), "");

				for (std::sregex_iterator i = std::sregex_iterator(Script.begin(), Script.end(), Variable);
					i != std::sregex_iterator();
					++i)
				{
					std::smatch m = *i;
					return m[1].str();
				}

			}
		}
		return "Unknown";
	}
	/*
     Find version of the obfuscator (maily for PSU)
	*/
	std::string FindVersion(std::string Script) {
		std::regex Version("This file was obfuscated using PSU Obfuscator (.*?) ");
		for (std::sregex_iterator i = std::sregex_iterator(Script.begin(), Script.end(), Version);
			i != std::sregex_iterator();
			++i)
		{
			std::smatch m = *i;
			return m[1].str();
		}
	}

}
