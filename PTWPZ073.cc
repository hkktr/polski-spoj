// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int PhoneKeypadNumber(char letter) {
  if (letter >= 'A' && letter <= 'C') return 2;
  if (letter >= 'D' && letter <= 'F') return 3;
  if (letter >= 'G' && letter <= 'I') return 4;
  if (letter >= 'J' && letter <= 'L') return 5;
  if (letter >= 'M' && letter <= 'O') return 6;
  if (letter >= 'P' && letter <= 'S') return 7;
  if (letter >= 'T' && letter <= 'V') return 8;
  if (letter >= 'W' && letter <= 'Z') return 9;
  return -1;
}

int main() {
  int n;
  std::cin >> n;

  std::string text;
  while (--n >= 0) {
    std::cin >> text;

    for (char letter : text) {
      std::cout << PhoneKeypadNumber(letter);
    }
    std::cout << "\n";
  }

  return 0;
}