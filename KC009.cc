// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::string text;
  while (std::cin >> text) {
    for (auto it{text.rbegin()}; it != text.rend(); ++it) {
      std::cout << *it;
    }
    std::cout << "\n";
  }

  return 0;
}