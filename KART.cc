// C++14 (gcc 8.3)
#include <iostream>

int FactorialTrailingZeroes(int n) {
  int result{0};
  while (n >= 5) {
    n /= 5;
    result += n;
  }

  return result;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::cout << FactorialTrailingZeroes(n) << "\n";
  }

  return 0;
}