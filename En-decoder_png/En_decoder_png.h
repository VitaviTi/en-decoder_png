#pragma once

#include "BitConvert.h"
#include "PNGeditor.h"



#ifdef API_DLL
#define API_DLL __declspec(dllexport)
#else
#define API_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	//Convertion binary code and string
	BitConvert bit_converter;

	//Working with png files
	PNGeditor png_editor;

	//Encoding the text in the png file
	API_DLL void encode_png(const wchar_t* wtext, const wchar_t* wfilepath);

	//Decoding the text in the png file
	API_DLL char* decode_png(const wchar_t* wfilepath);

#ifdef __cplusplus
}
#endif
