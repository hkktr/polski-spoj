// C++14 (gcc 8.3)
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  std::cout << std::setprecision(2) << std::fixed;
  while (--d >= 0) {
    int x1, y1, r1;
    std::cin >> x1 >> y1 >> r1;
    int x2, y2, r2;
    std::cin >> x2 >> y2 >> r2;

    std::cout << std::max(std::min(2 * r1, 2 * r2) -
                              std::max(std::hypot(x1 - x2, y1 - y2) -
                                           std::max(r1, r2) + std::min(r1, r2),
                                       0.0),
                          0.0)
              << "\n";
  }

  return 0;
}