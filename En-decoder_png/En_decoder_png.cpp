#include "En_decoder_png.h"

#include <iostream>

void encode_png(const wchar_t* wtext, const wchar_t* wfilepath)
{
	try
	{
		//convert text and filepath in string
		std::wstring wstrtext(wtext);
		std::string text(wstrtext.begin(), wstrtext.end());

		std::wstring wstrfilepath(wfilepath);
		std::string filepath(wstrfilepath.begin(), wstrfilepath.end());

		
		png_editor.encode_png(bit_converter.string_convert(text), filepath.c_str());
	}
	catch (std::logic_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

char* decode_png(const wchar_t* wfilepath)
{
	try
	{
		//convert filepath in string
		std::wstring wstrfilepath(wfilepath);
		std::string filepath(wstrfilepath.begin(), wstrfilepath.end());
		

		std::string text = bit_converter.bits_convert(png_editor.decode_png(filepath.c_str()));

		//Creating a copy of the text for a normalized data transfer
		return strcpy(new char[text.length()], text.c_str());
	}
	catch (std::logic_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
