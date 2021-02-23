// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::string text_number;
  std::cin >> text_number;

  int result{0};
  for (char character : text_number) {
    if (character >= 'a' && character <= 'i') {
      result += static_cast<int>(character + 1 - 'a');
    } else if (character >= 'k' && character <= 't') {
      result += static_cast<int>(character + 1 - 'k') * 10;
    } else if (character == 'v') {
      result += 200;
    } else if (character >= 'x' && character <= 'z') {
      result += static_cast<int>(character + 3 - 'x') * 100;
    }
  }

  std::cout << result;

  return 0;
}