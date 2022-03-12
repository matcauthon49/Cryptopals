#include "reference.h"
#include <string>
#include <iostream>
#include <vector>

const std::string x = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
std::vector<unsigned char> w;
const std::string ref = "ABCDEFGHIJKLMNOPQERSTUVWXYZ";

std::vector<unsigned char> chex(std::vector<unsigned char> a, unsigned char b) {
    std::vector<unsigned char> y;
    for (int i = 0; i < a.size(); i++){
        y.push_back(a[i] ^ b);
    }
    return y;
}

std::vector<unsigned char> hex_to_b256(std::vector<unsigned char> w) {
    std::vector<unsigned char> ascii;
    if (w.size() % 2 == 0) {
        for (int i = 0; i < w.size(); i = i+2){
            ascii.push_back(w[i]*16 + w[i+1]);
        }
    }
    else if (w.size() % 2 == 1) {
        ascii.push_back(w[0]);
        for (int i = 1; i < w.size(); i = i+2){
            ascii.push_back(w[i]*16 + w[i+1]);
        }
    }
    return ascii;
}

int main() {
    for (unsigned char i = 0; i < ref.size(); i++) {
        std::vector<unsigned char> w = char_xor(hex_to_b256(hex_decode(x)), ref[i]);
        for (int j = 0; j < w.size(); j++) {
            std::cout << w[j];
        }
        std::cout << "\n";
    }
}
