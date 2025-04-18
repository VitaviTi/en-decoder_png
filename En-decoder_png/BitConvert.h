#pragma once

#include <vector> // vector ; .pop_back() ; .insert()
#include <sstream> //stringstream
#include <bitset> //bitset<8> ; .to_ulong()

class BitConvert
{
private:
	//Checking the string for encoding ascii
	bool this_ascii(const std::string& text);
	//Translation of the decimal number into binary code
	void DecToBin(int n, std::vector<char>& bits);
public:
	//Converts a set of bits into a string
	std::string bits_convert(const std::vector<char>& bits);
	//Converts the string into a set of bits
	std::vector<char> string_convert(const std::string& text);
};

