// C++14 (gcc 8.3)
#include <iomanip>
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  std::cout << std::fixed << std::setprecision(2);
  while (--d >= 0) {
    double a, b;
    std::cin >> a >> b;
    std::cout << (100 * a + 100 * b - a * b) / 100 << "\n";
  }

  return 0;
}