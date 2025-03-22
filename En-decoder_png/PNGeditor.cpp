#include "PNGeditor.h"

unsigned int PNGeditor::read_size(const std::vector<char> bytes)
{
	std::stringstream ss;
	std::bitset<32> bits_bitset;

	for (size_t i = 0; i < 32; ++i)
	{
		ss << (int)bytes[i];
	}
	ss >> bits_bitset;
	return bits_bitset.to_ulong();
}

void PNGeditor::read_png(const char* file_path)
{
	m_File_path = file_path;

	//Open file for read
	FILE* fp;
	fopen_s(&fp, m_File_path.c_str(), "rb");
	if (fp == NULL) {
		throw std::invalid_argument("Error occured while opening. File not found.");
	}

	//Create png read struct
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		throw std::logic_error("Creation error png_create_read_struct");
	}

	//Create info struct(pixel data information)
	m_Info_ptr = png_create_info_struct(png_ptr);
	if (!m_Info_ptr) {
		throw std::logic_error("Creation error png_create_info_struct");
	}

	//setjmp
	if (setjmp(png_jmpbuf(png_ptr))) {
		throw std::logic_error("png_jmpbuf error");
	}

	// Reading a file in the PNG structure
	png_init_io(png_ptr, fp);
	png_read_png(png_ptr, m_Info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

	//Reading the size of the image and its pixelsé
	m_Width = png_get_image_width(png_ptr, m_Info_ptr);
	m_Height = png_get_image_height(png_ptr, m_Info_ptr);

	m_Row_pointers = png_get_rows(png_ptr, m_Info_ptr);

	//Destroy the PNG structure and closing a file
	png_destroy_read_struct(&png_ptr, NULL, NULL);
	fclose(fp);
}

std::vector<char> PNGeditor::decode_png(const char* file_path)
{
	read_png(file_path); // reading png file

	//Checking for the ability to read the size of the encoded text
	if ((m_Height + 1) * (m_Width + 1) * 4 < 32) {
		throw std::logic_error("The image is small for decoding");
	}

	//Reading bits from the image
	std::vector<char> result;
	unsigned int read_limit = 0;

	for (size_t y = 0; y < m_Height; ++y) {
		for (size_t x = 0; x < m_Width; ++x) {
			png_bytep px = &(m_Row_pointers[y][x * 4]);
			for (size_t j = 0; j < 4; ++j)
			{
				if (result.size() == 32 && read_limit == 0)
				{
					read_limit = read_size(result);
					result.clear();
				}
				if (read_limit != 0 && result.size() == read_limit) {
					return result;
				}

				//Reading bits
				if (px[j] % 2 == 0) {
					result.push_back(0);
				}
				else {
					result.push_back(1);
				}
			}
		}
	}
	return result;
}

void PNGeditor::encode_png(const std::vector<char>& bits, const char* file_path)
{
	read_png(file_path); // reading png file

	//Checking the ability to record the entire binary code in the image
	if (bits.size() > (m_Width + 1) * (m_Height + 1) * 4) {
		throw std::logic_error("The size of the string is large for recording");
	}

	if (bits.size() == 0) {
		throw std::logic_error("There were no bits on the record");
	}

	//Open file for write
	FILE* fp;
	fopen_s(&fp, m_File_path.c_str(), "wb");
	if (fp == NULL) {
		throw std::invalid_argument("Error occured while opening. File not found.");
	}

	//Create write struct
	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		throw std::logic_error("Creation error png_create_write_struct");
	}

	//setjmp
	if (setjmp(png_jmpbuf(png_ptr))) {
		throw std::logic_error("png_jmpbuf error");
	}

	png_init_io(png_ptr, fp);

	//Bits encode in pixels images
	unsigned int counter = 0;
	for (size_t y = 0; y < m_Height; ++y) {
		for (size_t x = 0; x < m_Width; ++x) {
			png_bytep px = &(m_Row_pointers[y][x * 4]);
			for (size_t j = 0; j < 4; ++j)
			{
				if (px[j] % 2 == 0 && bits[counter] == 1) {
					px[j]++;
				}
				else if (px[j] % 2 != 0 && bits[counter] == 0) {
					px[j]--;
				}

				counter++;
				if (counter == bits.size()) {
					png_set_rows(png_ptr, m_Info_ptr, m_Row_pointers);
					png_write_png(png_ptr, m_Info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
					png_destroy_write_struct(&png_ptr, &m_Info_ptr);
					fclose(fp);
					return;
				}
			}
		}
	}
	png_destroy_write_struct(&png_ptr, &m_Info_ptr);
	fclose(fp);
}