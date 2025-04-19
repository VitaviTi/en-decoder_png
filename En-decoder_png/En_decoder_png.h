#pragma once

#include "BitConvert.h"
#include "PNGeditor.h"

#ifdef __cplusplus
extern "C" {
#endif

	//Convertion binary code and string
	BitConvert bit_converter;

	//Working with png files
	PNGeditor png_editor;

	
	//Encoding the text in the png file
	__declspec(dllexport) void encode_png(std::string text, std::string filepath);	

	//Decoding the text in the png file
	__declspec(dllexport) std::string decode_png(const char* filepath);

#ifdef __cplusplus
}
#endif
