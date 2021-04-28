// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;

  std::string number;
  while (--t >= 0) {
    int n;
    std::cin >> n;

    number.reserve(n);
    std::cin >> number;

    int coefficient{1};
    int exponent{0};

    if (n == 1 && number[0] == '?') {
      exponent = 1;
    } else {
      if (number[0] == '?') {
        coefficient = 9;
      }

      for (int i{1}; i < n; ++i) {
        if (number[i] == '?') {
          ++exponent;
        }
      }
    }

    std::cout << coefficient;
    for (int i{0}; i < exponent; ++i) {
      std::cout << 0;
    }
    std::cout << "\n";
  }

  return 0;
}