// C++14 (gcc 8.3)
#include <iostream>

bool IsValidTriangle(double a, double b, double c) {
  if (a + b > c && a + c > b && b + c > a) return true;
  return false;
}

int main() {
  double a, b, c;
  while (std::cin >> a >> b >> c) {
    std::cout << IsValidTriangle(a, b, c) << "\n";
  }

  return 0;
}