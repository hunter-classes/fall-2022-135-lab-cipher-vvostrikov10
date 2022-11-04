#include <iostream>
#include "caesar.h"
#include "vigenere.h"

std::string encryptVigenere(std::string plaintext, std::string keyword){
    int i;
    int c = 0;
    std::string ans(plaintext.length(), '*');
    int shift = 0;
    for (i = 0; i < plaintext.length(); i++){
        if (isalpha(plaintext[i])){
            if (isupper(keyword[c])) shift = keyword[c] - 'A';
            else if (islower(keyword[c])) shift = keyword[c] - 'a';
            else shift = 0;
            ans[i] = shiftChar(plaintext[i], shift);
            c++;
            c %= keyword.length();
        }
        else{
            ans[i] = plaintext[i];
        }
    }
    return ans;
}