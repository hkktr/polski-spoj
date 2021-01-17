// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  constexpr int last_digits[10][4] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {6, 2, 4, 8}, {1, 3, 9, 7}, {6, 4, 6, 4},
      {5, 5, 5, 5}, {6, 6, 6, 6}, {1, 7, 9, 3}, {6, 8, 4, 2}, {1, 9, 1, 9}};

  while (--d >= 0) {
    int base, exponent;
    std::cin >> base >> exponent;
    std::cout << last_digits[base % 10][exponent % 4] << "\n";
  }

  return 0;
}