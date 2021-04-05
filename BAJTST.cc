// C++14 (gcc 8.3)
#include <cmath>
#include <iomanip>
#include <iostream>

double TriangleArea(int a, int b, int c) {
  const double s{(a + b + c) / 2.0};
  return std::sqrt(static_cast<double>(s * (s - a) * (s - b) * (s - c)));
}

bool IsValidTriangle(int a, int b, int c) {
  if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))) {
    return true;
  }
  return false;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    double k;
    std::cin >> n >> k;

    double total_area{0};
    while (--n >= 0) {
      int a, b, c;
      std::cin >> a >> b >> c;

      if (IsValidTriangle(a, b, c)) {
        total_area += TriangleArea(a, b, c);
      }
    }

    std::cout << std::setprecision(1000) << std::round(total_area * k / 10)
              << "\n";
  }

  return 0;
}