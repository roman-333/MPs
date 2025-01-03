#include <iostream>

#include "functions.hpp"

int main(int argc, char** argv) {
  // Checks if arguments were passed correctly
  if (argc != 2) {
    std::cout << "Correct usage: ./bin/exec \"hawaiian word\"" << std::endl;
    return 1;
  }
//  initialize hawaiian_word with passed in argument
  std::string hawaiian_word = argv[1];

//  prints the result of GetPronunciation to terminal
  std::cout << GetPronunciation(hawaiian_word) << std::endl;
}
/* Notes:
  12 valid characters in the Hawaiian language: a, e, i, o, u, p, k, h, l, m, n, and w. 
  A valid Hawaiian word must start with a vowel or 'p', followed by any combination
  

*/