#include <string>
#include <iostream>
#include <vector>

const std::string hex_ref = "0123456789abcdef";
const std::string base64_ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz"
                               "0123456789+/";

unsigned char char_decode_hex(char input)
{
  if(input >= '0' && input <= '9')
    return input - '0';
  if(input >= 'A' && input <= 'F')
    return input - 'A' + 10;
  if(input >= 'a' && input <= 'f')
    return input - 'a' + 10;
  throw std::invalid_argument("Invalid input string");
}

std::vector<unsigned char> hex_decode(std::string hex_string) {
    std::vector<unsigned char> bytearray;
    for (int i = 0; i < hex_string.length(); i++) {
        unsigned char ch = char_decode_hex(hex_string[i]);
        bytearray.push_back(ch);
    }
    return bytearray;
}


std::vector<unsigned char> hex_to_base64(std::vector<unsigned char> hex_bytearray) {
    std::vector<unsigned char> binary_array;
    std::vector<unsigned char> base64_bytearray;
    for (int i = 0; i < hex_bytearray.size(); i++) {
        binary_array.push_back(hex_bytearray[i]/4);
        binary_array.push_back(hex_bytearray[i]%4);
    }
    int offset = binary_array.size()%3;
    // std::cout << offset << "\n";
    if (offset == 0) {
        for (int  i = 0; i < binary_array.size(); i = i + 3){
            unsigned char b64_byte = binary_array[i]*16 + binary_array[i+1]*4 + binary_array[i+2];
            base64_bytearray.push_back(b64_byte);
        }
    }
    else if (offset == 1) {
        base64_bytearray.push_back(binary_array[0]);
        for (int  i = 1; i < binary_array.size(); i = i + 3){
            unsigned char b64_byte = binary_array[i]*16 + binary_array[i+1]*4 + binary_array[i+2];
            base64_bytearray.push_back(b64_byte);
        }
    }
    else if (offset == 2) {
        base64_bytearray.push_back(binary_array[0]*4 + binary_array[1]);
        for (int  i = 2; i < binary_array.size(); i = i + 3){
            unsigned char b64_byte = binary_array[i]*16 + binary_array[i+1]*4 + binary_array[i+2];
            base64_bytearray.push_back(b64_byte);
        }
    }
    return base64_bytearray;
}

std::string byte_to_base64(std::vector<unsigned char> bytearray) {
    std::string base64_string = "";
    for (int i = 0; i < bytearray.size(); i++) {
        unsigned char y = base64_ref[bytearray[i]];
        base64_string.push_back(y);
    }
    return base64_string;
}

std::vector<unsigned char> hex_xor(std::vector<unsigned char> a, std::vector<unsigned char> b) {
    std::vector<unsigned char> arr;
    
    for (int i = 0; i < a.size(); i++) {
        arr.push_back(a[i]^b[i]);
    }
    return arr;
}

std::string hex_encode(std::vector<unsigned char> bytearray) {
    std::string base64_string = "";

    for (int i = 0; i < bytearray.size(); i++) {
        unsigned char y = hex_ref[bytearray[i]];
        base64_string.push_back(y);
    }
    return base64_string;
}


std::vector<unsigned char> char_xor(std::vector<unsigned char> a, unsigned char b) {
    std::vector<unsigned char> arr;
    for (int i = 0; i < a.size(); i++) {
        arr.push_back(a[i]^b);
    }
    return arr;
}