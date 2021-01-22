// C++14 (gcc 8.3)
#include <iomanip>
#include <iostream>

int main() {
  constexpr double kPi{3.141592654};
  double r, d;

  std::cin >> r >> d;
  std::cout << std::setprecision(2) << std::fixed
            << (r * r - (d * d / 4.0)) * kPi;

  return 0;
}