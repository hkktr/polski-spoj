// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  int c;
  std::cin >> c;

  while (--c >= 0) {
    std::string text;
    std::cin >> text;

    std::string::size_type i{0};
    while (i < text.size()) {
      const char character{text[i]};
      int quantity{1};
      for (std::string::size_type j{i + 1}; j < text.size(); ++j) {
        if (text[j] == character) {
          ++quantity;
        } else {
          break;
        }
      }

      if (quantity <= 2) {
        for (int j{0}; j < quantity; ++j) {
          std::cout << character;
        }
      } else {
        std::cout << character << quantity;
      }
      i += quantity;
    }
    std::cout << "\n";
  }

  return 0;
}