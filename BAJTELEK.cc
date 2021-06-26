// C++14 (gcc 8.3)
#include <iostream>

long long GetArea() {
  int x0, y0;
  std::cin >> x0 >> y0;

  int last_x{x0}, last_y{y0};
  long long area{0};
  int x, y;
  while (std::cin >> x >> y) {
    area +=
        static_cast<long long>(last_x) * y - static_cast<long long>(last_y) * x;
    if (x == x0 && y == y0) break;
    last_x = x, last_y = y;
  }

  return area;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (--n >= 0) {
    long long gray_area{GetArea()};
    long long black_area{GetArea()};

    if (black_area > gray_area) std::swap(black_area, gray_area);
    std::cout << black_area * 2 + gray_area * 3 << "\n";
  }

  return 0;
}