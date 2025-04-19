#include "En_decoder_png.h"

void encode_png(std::string text, std::string filepath)
{
	try
	{
		png_editor.encode_png(bit_converter.string_convert(text), filepath.c_str());
	}
	catch (std::logic_error& e)
	{
		abort();
	}
}

std::string decode_png(const char* filepath)
{
	try
	{
		return bit_converter.bits_convert(png_editor.decode_png(filepath));
	}
	catch (std::logic_error& e)
	{
		abort();
	}
}
