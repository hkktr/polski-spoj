// C++14 (gcc 8.3)
#include <iostream>

inline int CharToInt(char digit) { return static_cast<int>(digit - '0'); }

int main() {
  int t;
  std::cin >> t;

  constexpr int kPeselValidationFormula[11]{1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
  while (--t >= 0) {
    int sum{0};
    for (int i{0}; i < 11; ++i) {
      char digit;
      std::cin >> digit;
      sum += CharToInt(digit) * kPeselValidationFormula[i];
    }

    std::cout << ((sum % 10 == 0) ? "D" : "N") << "\n";
  }

  return 0;
}