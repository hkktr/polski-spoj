// C++14 (gcc 8.3)
#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string text;
  while (std::getline(std::cin, text)) {
    int numbers{0}, words{0};
    if (isdigit(text[0])) {
      ++numbers;
    } else if (isalpha(text[0])) {
      ++words;
    }

    for (std::size_t i{1}; i < text.size(); ++i) {
      if (text[i] == ' ') {
        if (isdigit(text[i + 1])) {
          ++numbers;
        } else if (isalpha(text[i + 1])) {
          ++words;
        }
      }
    }

    std::cout << numbers << " " << words << "\n";
  }

  return 0;
}