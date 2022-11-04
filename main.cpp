#include <iostream>


#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include <vector>
#include <fstream>

int main(){
  std::vector<double> frankFrequencies = getFrequenciesFile("Frankenstein.txt");
  std::vector<double> danteFrequencies = getFrequenciesFile("Dante.txt");
  std::cout << "frequencies for Frankenstein:" << std::endl;
  for (int i = 0; i < frankFrequencies.size(); i++) std::cout << char('a' + i) << ' ' <<  frankFrequencies[i] << std::endl;
  std::cout << std::endl;
  std::cout << "frequencies for Dantes Inferno in Italian:" << std::endl;
  for (int i = 0; i < danteFrequencies.size(); i++) std::cout << char('a' + i) << ' ' << danteFrequencies[i] << std::endl;
  std::cout << std::endl;
  std::cout << "Deciphering using mary shelley\'s Frankenstein" << std::endl;
  std::cout << decryptCaesarDistance("Li pruh ri xv ydoxhg irrg dqg fkhhu dqg vrqj deryh krdughg jrog, lw zrxog eh d phuulhu zruog!", frankFrequencies) << std::endl;
  std::cout << "Deciphering using Dante\'s Inferno in italian" << std::endl;
  std::cout << decryptCaesarDistance("Li pruh ri xv ydoxhg irrg dqg fkhhu dqg vrqj deryh krdughg jrog, lw zrxog eh d phuulhu zruog!", danteFrequencies) << std::endl;
  return 0;
}
