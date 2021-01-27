// C++14 (gcc 8.3)
#include <iomanip>
#include <iostream>

int main() {
  double a, b, c;
  std::cin >> a >> b >> c;

  if (a == 0 && b != c) {
    std::cout << "BR\n";
  } else if (a == 0) {
    std::cout << "NWR\n";
  } else {
    std::cout << std::setprecision(2) << std::fixed << (c - b) / a << "\n";
  }

  return 0;
}