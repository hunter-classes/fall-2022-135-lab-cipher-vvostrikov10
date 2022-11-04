#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include <vector>



// add your tests here
TEST_CASE("<shiftChar tests>"){
    CHECK(shiftChar('a', 3) == 'd');
    CHECK(shiftChar('A', 5) == 'F');
    CHECK(shiftChar('z', 3) == 'c');
    CHECK(shiftChar('Z', 5) == 'E');
    CHECK(shiftChar(',', 3) == ',');
    CHECK(shiftChar('a', 29) == 'd');
    CHECK(shiftChar('a', 55) == 'd');
    CHECK(shiftChar('a', -49) == 'd');
}

TEST_CASE("<encryptCaesar tests>"){
    CHECK(encryptCaesar("abc", 3) == "def");
    CHECK(encryptCaesar("abc", 29) == "def");
    CHECK(encryptCaesar("Caesar", 3) == "Fdhvdu");
    CHECK(encryptCaesar("Cipher!", -3) == "Zfmebo!");
    CHECK(encryptCaesar("", 3) == "");    
}

TEST_CASE("<encryptVigenere tests>"){
    CHECK(encryptVigenere("abc", "d") == "def");
    CHECK(encryptVigenere("abc", "abc") == "ace");
    CHECK(encryptVigenere("abc", "abcdefg") == "ace");
    CHECK(encryptVigenere("Vigenere Cipher!?!", "Code") == "Xwjipsui Ewslgf!?!");
}

TEST_CASE("<decryptCaesar tests>"){
    CHECK(decryptCaesar("def", 3) == "abc");
    CHECK(decryptCaesar("def", 29) == "abc");
    CHECK(decryptCaesar("Fdhvdu", 3) == "Caesar");
    CHECK(decryptCaesar("Zfmebo!", -3) == "Cipher!");
    CHECK(decryptCaesar("", 3) == "");
}

TEST_CASE("<decryptVigenere tests>"){
    CHECK(decryptVigenere("def", "d") == "abc");
    CHECK(decryptVigenere("ace", "abc") == "abc");
    CHECK(decryptVigenere("ace", "abcdefg") == "abc");
    CHECK(decryptVigenere("Xwjipsui Ewslgf!?!", "Code") == "Vigenere Cipher!?!");
}

TEST_CASE("<decrypCaesarDistance tests>"){
    std::vector<double> frankFrequencies = getFrequenciesFile("Frankenstein.txt");
    CHECK(decryptCaesarDistance("Zynp fazy l xtoytrse ocplcj, hstwp T azyopcpo, hplv lyo hplcj,", frankFrequencies) == "Once upon a midnight dreary, while I pondered, weak and weary,");
    CHECK(decryptCaesarDistance("Pwfs nboz b rvbjou boe dvsjpvt wpmvnf pg gpshpuufo mpsf—", frankFrequencies) == "Over many a quaint and curious volume of forgotten lore—");
    CHECK(decryptCaesarDistance("Bmnqj N stiiji, sjfwqd sfuunsl, xziijsqd ymjwj hfrj f yfuunsl,", frankFrequencies) == "While I nodded, nearly napping, suddenly there came a tapping,");
    CHECK(decryptCaesarDistance("Gy ul yusk utk mktzre xgvvotm, xgvvotm gz se ingshkx juux.", frankFrequencies) == "As of some one gently rapping, rapping at my chamber door.");
    CHECK(decryptCaesarDistance("“’Kzj jfdv mzjzkfi,” Z dlkkvivu, “krggzex rk dp tyrdsvi uffi—", frankFrequencies) == "“’Tis some visitor,” I muttered, “tapping at my chamber door—");
    CHECK(decryptCaesarDistance("Hger mabl tgw ghmabgz fhkx.", frankFrequencies) == "Only this and nothing more.");
}