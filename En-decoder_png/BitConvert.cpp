#include "BitConvert.h"

//Checking the string for encoding ascii
bool BitConvert::this_ascii(const std::string& text)
{
	char ch = 0;
	for (size_t i = 0; i < text.size(); ++i)
	{
		ch = text[i];
		if (ch < 0 || ch > 127)
		{
			return false;
		}
	}
	return true;
}

//Translation of the decimal number into binary code
void BitConvert::DecToBin(int n, std::vector<char>& bits)
{
	while (n != 0)
	{
		if (n % 2 == 0) {
			bits.insert(bits.begin(), 0);
		}
		else {
			bits.insert(bits.begin(), 1);
		}
		n /= 2;
	}
}



//Converts a set of bits into a string
std::string BitConvert::bits_convert(const std::vector<char>& bits)
{
	//Checking the size of the bits vector
	if (bits.size() == 0) {
		return "";
	}

	std::vector<char> bits_tr = bits;
	std::string result{ "" };

	//Removing the last bits so that data can be used as bytes
	while (bits_tr.size() % 7 != 0) {
		bits_tr.pop_back();
	}

	//Translate  each byte to ASCII symbol and adding to result string
	for (size_t i = 0; i < bits_tr.size(); i += 7)
	{
		std::stringstream ss;
		std::bitset<7> bits_bitset;
		for (size_t j = i; j < (i + 7); j++)
		{
			ss << (int)bits_tr[j];
		}
		ss >> bits_bitset;
		result.insert(result.begin(), char(bits_bitset.to_ulong()));
	}
	return result;
}

//Converts the string into a set of bits
std::vector<char> BitConvert::string_convert(const std::string& text)
{
	//Checking the string for size
	if (text.size() == 0) {
		return {};
	}

	//Checking the string for encoding ASCII
	if (!this_ascii(text)) {
		throw std::invalid_argument("The text contains symbols that are not included in the encoding of ASCII");
	}

	//converting string in bits
	std::vector<char> result{};

	for (size_t i = 0; i < text.size(); ++i)
	{
		//Convert each symbol of the string into bits
		DecToBin((int)text[i], result);
		//Complement the end of each byte to 7 bits
		do result.insert(result.begin(), 0);
		while (result.size() % 7 != 0);

	}

	//If the size of the result is more than 4 bytes
	if (result.size() > 4294967296) {
		throw std::logic_error("The length of the byte text exceeds the permissible");
	}

	//Writing the vector result size in 4 byte
	std::vector<char> byte_length{};
	int n = result.size();

	DecToBin(result.size(), byte_length);
	do byte_length.insert(byte_length.begin(), 0);
	while (byte_length.size() % 32 != 0);

	result.insert(result.begin(), byte_length.begin(), byte_length.end());

	return result;
}