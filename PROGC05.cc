// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  char letter;
  std::string text;
  while (std::cin >> letter >> text) {
    std::string result;
    result.reserve(text.size());
    for (char i : text) {
      if (i != letter) result += i;
    }

    std::cout << result << "\n";
  }

  return 0;
}