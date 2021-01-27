// C++14 (gcc 8.3)
#include <iostream>

int main() {
  double a, b, c;
  while (std::cin >> a >> b >> c) {
    const double delta{b * b - 4 * a * c};
    if (delta < 0) {
      std::cout << 0;
    } else if (delta == 0) {
      std::cout << 1;
    } else if (delta > 0) {
      std::cout << 2;
    }
    std::cout << "\n";
  }

  return 0;
}