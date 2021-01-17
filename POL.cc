// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;

  std::string text;
  while (--t >= 0) {
    std::cin >> text;
    std::cout << text.substr(0, text.length() / 2) << "\n";
  }

  return 0;
}