#include <string>
#include <iostream>
#include <vector>
#include <bitset>

const std::string hex_ref = "0123456789abcdef";
const unsigned int hex_ref_2[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
                                    0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
                                    0x0c, 0x0d, 0x0e, 0x0f};

const std::string x = "1c0111001f010100061a024b53535009181c";
const std::string y = "686974207468652062756c6c277320657965";

std::vector<unsigned char> hex_decode(std::string hex_string) {
    std::vector<unsigned char> bytearray;

    for (int i = 0; i < hex_string.length(); i++) {
        int loc = hex_ref.find(hex_string[i]);
        bytearray.push_back(hex_ref_2[loc]);
    }
    return bytearray;
}

std::string hex_encode(std::vector<unsigned char> bytearray) {
    std::string base64_string = "";

    for (int i = 0; i < bytearray.size(); i++) {
        unsigned char x = bytearray[i];
        unsigned char y = hex_ref[x];
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

int main() {
    std::cout << hex_encode(hex_xor(hex_decode(x), hex_decode(y)));
}