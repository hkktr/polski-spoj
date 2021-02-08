// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::string text;
  while (std::getline(std::cin, text)) {
    for (char& character : text) {
      if (character >= 'A' && character <= 'Z') {
        character += 3;
        if (character > 'Z') character -= ('Z' - 'A') + 1;
      }
    }
    std::cout << text << "\n";
  }

  return 0;
}