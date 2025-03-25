#include "En_decoder_png.h"

void En_decoder_png::encode_png(std::string text, const char* filepath)
{
	png_editor.encode_png(bit_converter.string_convert(text), filepath);
}

std::string En_decoder_png::decode_png(const char* filepath)
{
	return bit_converter.bits_convert(png_editor.decode_png(filepath));
}
