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

	
	//variable describing the number of the exception
	__declspec(dllexport) int num = 0;
	// 1 - logic_error - program error
	// 2 - invalid_argument - user error


	//Encoding the text in the png file
	__declspec(dllexport) void encode_png(std::string text, std::string filepath);	

	//Decoding the text in the png file
	__declspec(dllexport) std::string decode_png(const char* filepath);

#ifdef __cplusplus
}
#endif
