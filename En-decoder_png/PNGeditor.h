#pragma once

#include <stdio.h> //FILE* ; fopen_s() ; flclose()
#include <stdexcept> // logic_error() ; invalid_argument() 
#include <sstream> //stringstream
#include <bitset> //bitset<8> ; .to_ulong()
#include <vector> // vector ; .push_back()

#include <png.h>

class PNGeditor
{
	png_infop m_Info_ptr;
	//rgba pixels array
	png_bytepp m_Row_pointers;

	//Was the image read?
	bool m_Read = false;

	//sizes image
	int m_Width = 0;
	int m_Height = 0;

	//Path to the png image
	std::string m_File_path;

private:
	//char decToLastBin(int n);
	unsigned int read_size(const std::vector<char> bytes);

public:
	//reading png file and sizes image and rgba pixels 
	void read_png(const char* file_path);

	//Reads bits encoded in the file
	std::vector<char> decode_png();
	//encodes the received bits in the last bits of RGBA image
	void encode_png(const std::vector<char>& bits);
};

