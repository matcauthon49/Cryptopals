#include <string>
#include <iostream>
#include <vector>

// ------------------ Reference Strings -----------------------

const std::string hex_ref = "0123456789abcdef";
const std::string base64_ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz"
                               "0123456789+/";

// ------------------ Decode Hex -----------------------

std::vector<unsigned char> hex_to_byte(std::string hex_string) {
  
    std::vector<unsigned char> bytearray;
  
    for (int i = 0; i < hex_string.length(); i++) {
        int loc = hex_ref.find(hex_string[i]);
        bytearray.push_back(loc);
    }
  
    return bytearray;
}

// ------------------ Convert Decoded Hex to Base64 -----------------------

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

// ------------------ Encode Base64 -----------------------

std::string byte_to_base64(std::vector<unsigned char> bytearray) {
  
    std::string base64_string = "";
  
    for (int i = 0; i < bytearray.size(); i++) {
      
        unsigned char x = bytearray[i];
        unsigned char y = base64_ref[x];
      
        base64_string.push_back(y);
    }
  
    return base64_string;
}

// ------------------ Complete Converter Function -----------------------

std::string hex_converter(std::string x) {
    return byte_to_base64(hex_to_base64(hex_to_byte(x)));
}

// ------------------ Print -----------------------

int main(){
    std::cout << hex_converter("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
}
