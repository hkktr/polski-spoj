// C++14 (gcc 8.3)
#include <iostream>

long long RedSquares(long long x, long long y) {
  if (x < y) std::swap(x, y);
  if (x < 2 || y == 0) return 0;

  if (y < 2) {
    return x / 2;
  } else {
    return ((6 + (y / 2 - 1) * 4) / 2) * (y / 2) + ((x - y + (y % 2)) / 2) * y;
  }
}

int main() {
  long long x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  std::cout << RedSquares(x2, y2) + RedSquares(x1, y1) - RedSquares(x2, y1) -
                   RedSquares(x1, y2);

  return 0;
}