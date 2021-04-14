// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::string text;
  while (std::getline(std::cin, text)) {
    for (std::size_t i{1}; i < text.size(); i += 2) {
      std::swap(text[i - 1], text[i]);
    }
    std::cout << text << "\n";
  }

  return 0;
}