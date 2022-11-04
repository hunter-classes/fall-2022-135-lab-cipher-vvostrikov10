#include <vector>
#pragma once
std::string decryptCaesar(std::string ciphertext, int lshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);
std::vector<double> getFrequencies(std::string text);
std::string decryptCaesarDistance(std::string ciphertext, std::vector<double> frequencies);
std::vector<double> getFrequenciesFile(std::string fname);