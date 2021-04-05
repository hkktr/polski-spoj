// C++14 (gcc 8.3)
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  const double kPi{std::acos(-1.0)};

  int z;
  std::cin >> z;

  while (--z >= 0) {
    int d, n;
    std::cin >> d >> n;

    if (n % 2 == 0) n /= 2;
    const double cut_distance{kPi * 0.5 * d / n};

    std::cout << std::fixed << std::setprecision(3) << cut_distance << " " << n
              << "\n";
  }

  return 0;
}