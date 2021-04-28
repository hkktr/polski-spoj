// C++14 (gcc 8.3)
#include <array>
#include <cmath>
#include <iostream>

int main() {
  std::array<int, 26> letters{0};
  int letters_quantity{0};

  char character{'\0'};
  while ((character = static_cast<char>(std::getchar())) != '\n') {
    if (character != ' ') {
      ++letters[character - 'A'];
      ++letters_quantity;
    }
  }

  for (char letter{'A'}; letter <= 'Z'; ++letter) {
    std::cout << letter;

    int percentage{static_cast<int>(std::round(
        static_cast<double>(letters[letter - 'A']) / letters_quantity * 100))};
    while (--percentage >= 0) {
      std::cout << "*";
    }

    std::cout << "\n";
  }

  return 0;
}