#include <iostream>
#include "caesar.h"
#include <string>

// add functions here
char shiftChar(char c, int rshift){
    if (islower(c)){
        c -= 'a';
        c += rshift;
        if (c < 0) c = c + 26 * (-c / 26 + 1);
        c %= 26;
        //std::cout << (int)c << std::endl;
        c += 'a';
    }
    if (isupper(c)){
        c -= 'A';
        c += rshift;
        if (c < 0) c = c + 26 * (-c / 26 + 1);
        c %= 26;
        c += 'A';
    }
    return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
    int i;
    std::string ans(plaintext.length(), '*');
    for (i = 0; i < plaintext.length(); i++){
        ans[i] = shiftChar(plaintext[i], rshift);
    }
    return ans;
}



