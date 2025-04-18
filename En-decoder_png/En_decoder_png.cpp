#include "En_decoder_png.h"

void encode_png(std::string text, std::string filepath)
{
	try
	{
		num = 0;
		png_editor.encode_png(bit_converter.string_convert(text), filepath.c_str());
	}
	catch (std::invalid_argument& e)
	{
		num = 1;
	}
	catch (std::logic_error& e)
	{
		num = 2;
	}
}

std::string decode_png(const char* filepath)
{
	try
	{
		num = 0;
		return bit_converter.bits_convert(png_editor.decode_png(filepath));
	}
	catch (std::invalid_argument& e)
	{
		num = 1;
	}
	catch (std::logic_error& e)
	{
		num = 1;
	}
}
