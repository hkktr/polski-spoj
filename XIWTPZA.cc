// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    double a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;

    if (a1 < a2) std::swap(a1, a2);
    if (b1 < b2) std::swap(b1, b2);

    if (a1 > b1 && a2 > b2) {
      std::cout << "TAK\n";
    } else if (a1 <= b1 && a2 <= b2) {
      std::cout << "NIE\n";
    } else {
      const double d1{std::hypot(a1, a2)};
      const double d2{std::hypot(b1, b2)};

      if (d1 <= d2) {
        std::cout << "NIE\n";
      } else {
        const double a{0.5 * a1 - std::sqrt(std::pow(0.5 * d2, 2) -
                                            std::pow(0.5 * a2, 2))};
        const double b{0.5 * a2 - std::sqrt(std::pow(0.5 * d2, 2) -
                                            std::pow(0.5 * a1, 2))};
        const double c{std::hypot(a, b)};

        if (c > b2) {
          std::cout << "TAK\n";
        } else {
          std::cout << "NIE\n";
        }
      }
    }
  }

  return 0;
}