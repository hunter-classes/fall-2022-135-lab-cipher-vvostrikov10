#include <iostream>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include <vector>
#include <cmath>
#include <fstream>

std::string decryptCaesar(std::string ciphertext, int lshift){
    return encryptCaesar(ciphertext, -lshift);
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
    int i;
    int c = 0;
    std::string ans(ciphertext.length(), '*');
    int shift = 0;
    for (i = 0; i < ciphertext.length(); i++){
        if (isalpha(ciphertext[i])){
            if (isupper(keyword[c])) shift = keyword[c] - 'A';
            else if (islower(keyword[c])) shift = keyword[c] - 'a';
            else shift = 0;
            ans[i] = shiftChar(ciphertext[i], -shift);
            c++;
            c %= keyword.length();
        }
        else{
            ans[i] = ciphertext[i];
        }
    }
    return ans;
}

std::vector<double> getFrequencies(std::string text){
    std::vector<double> ans(26, 0);
    int c = 0;
    for(int i = 0; i < text.length(); i++){
        if (islower(text[i])){
            ans[text[i] - 'a']++;
            c++;
        }
        else if(isupper(text[i])){
            ans[text[i] - 'A']++;
            c++;
        }
    }
    for(int i = 0; i < 26; i++){
        ans[i] = ans[i] / c;
    }
    return ans;
}

std::vector<double> getFrequenciesFile(std::string fname){
    std::ifstream in(fname);
    std::vector<double> ans(26, 0);
    int c = 0;
    std::string text;
    while(std::getline(in, text)){
        for(int i = 0; i < text.length(); i++){
            if (islower(text[i])){
                ans[text[i] - 'a']++;
                c++;
            }
            else if(isupper(text[i])){
                ans[text[i] - 'A']++;
                c++;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        ans[i] = ans[i] / c;
    }
    in.close();
    return ans;
}

double distance(std::vector<double> v1, std::vector<double> v2){
    double ans = 0;
    for(int i = 0;  i < 26; i++){
        ans += (v2[i] - v1[i]) * (v2[i] - v1[i]);
    }
    return sqrt(ans);
}

std::string decryptCaesarDistance(std::string ciphertext, std::vector<double> frequencies){
    std::string winner;
    double minDistance = 10000;
    for(int i = 0; i < 26; i++){
        std::string challenger = encryptCaesar(ciphertext, i);
        std::vector<double> challengerFrequencies = getFrequencies(challenger);
        double dist = distance(frequencies, challengerFrequencies);
        if (dist < minDistance){
            winner = challenger;
            minDistance = dist;
        }
    }
    return winner;
}