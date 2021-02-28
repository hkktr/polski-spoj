// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    double x, y, z;
    std::cin >> x >> y >> z;

    std::cout << std::round((x + y - z * y) * -12.0 / (z - 1.0)) << "\n";
  }

  return 0;
}