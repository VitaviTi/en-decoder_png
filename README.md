# Encoder/decoder text in the png file

## Code 
This program consists of 2 classes

### class PNGeditor
Classes working with *.png files

Class containing 2 public methods:

**decode_png** - decode the message encoded in *.png, reads the length recorded in the first 4 bytes of the encrypted message, then the message itself is coming.

**encode_png** - encode the length of the message in the first 4 bytes and the message itself in *.png file.

And one private method:

**read_png** - reading the *.PNG file, is caused at first of each public function to update the file information.

### class BitConvert
Class converting an array of bits into a string and a string into the bits array.

Contains 2 public methods:

**bits_conver** - converts bits into a string.

**string_convert** - converts the string into the bits array

And two private methods:

**this_ascii** - checking the string for encoding ascii. If the symbols of the string go beyond the coding, then it returns a false.

**DecToBin** - converts the decimal system in the binary number system.