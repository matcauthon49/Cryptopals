#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include <iostream>
#include <vector>

unsigned char char_decode_hex(char input);
std::vector<unsigned char> hex_decode(std::string hex_string);
std::vector<unsigned char> hex_to_base64(std::vector<unsigned char> hex_bytearray);
std::string byte_to_base64(std::vector<unsigned char> bytearray);
std::vector<unsigned char> hex_xor(std::vector<unsigned char> a, std::vector<unsigned char> b);
std::string hex_encode(std::vector<unsigned char> bytearray);
std::vector<unsigned char> char_xor(std::vector<unsigned char> a, unsigned char b);

#endif