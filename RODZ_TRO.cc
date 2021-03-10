// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  double a, b, c;
  while (std::cin >> a >> b >> c) {
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);

    if (a + b <= c) {
      std::cout << "brak";
    } else if (std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2)) {
      std::cout << "prostokatny";
    } else if (std::pow(a, 2) + std::pow(b, 2) < std::pow(c, 2)) {
      std::cout << "rozwartokatny";
    } else if (std::pow(a, 2) + std::pow(b, 2) > std::pow(c, 2)) {
      std::cout << "ostrokatny";
    }
    std::cout << "\n";
  }

  return 0;
}