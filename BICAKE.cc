// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  long long n;
  while (std::cin >> n) {
    if (n <= 1) {
      std::cout << "0\n";
    } else {
      std::cout << static_cast<long long>(
                       std::floor((1.0 + std::sqrt(1.0 + 8.0 * (n - 2))) / 2))
                << "\n";
    }
  }

  return 0;
}