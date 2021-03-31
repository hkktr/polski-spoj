// C++14 (gcc 8.3)
#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main() {
  const std::map<char, std::string> kMorseCode{
      {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
      {'F', ".-.."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
      {'K', "-.-"},  {'L', "..-."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
      {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
      {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
      {'Z', "--.."}, {' ', "/"}};
  const char kAfterLetter{'/'};

  std::string line;
  while (std::getline(std::cin, line)) {
    for (char character : line) {
      std::cout << kMorseCode.at(static_cast<char>(std::toupper(character)));
      if (std::isalpha(character)) std::cout << kAfterLetter;
    }
    std::cout << "\n";
  }

  return 0;
}