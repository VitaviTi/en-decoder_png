#pragma once

#include "BitConvert.h"
#include "PNGeditor.h"

class En_decoder_png {
private:
	//Convertion binary code and string
	BitConvert bit_converter;

	//Working with png files
	PNGeditor png_editor;

public:

	//Encoding the text in the png file
	void encode_png(std::string text, const char* filepath);

	//Decoding the text in the png file
	std::string decode_png(const char* filepath);
};