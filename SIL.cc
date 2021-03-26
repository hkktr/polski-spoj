// C++ (gcc 8.3)
#include <cmath>
#include <iostream>

struct Point {
  int x, y;
};

int OverlappingArea(Point a1, Point a2, Point b1, Point b2) {
  const int area_a{std::abs(a1.x - a2.x) * std::abs(a1.y - a2.y)};
  const int area_b{std::abs(b1.x - b2.x) * std::abs(b1.y - b2.y)};

  const int x_distance{std::min(a2.x, b2.x) - std::max(a1.x, b1.x)};
  const int y_distance{std::min(a2.y, b2.y) - std::max(a1.y, b1.y)};

  int intersection_area{0};
  if (x_distance > 0 && y_distance > 0) {
    intersection_area = x_distance * y_distance;
  }

  return area_a + area_b - intersection_area;
}

int main() {
  Point a1, a2, b1, b2;
  std::cin >> a1.x >> a1.y >> a2.x >> a2.y;
  std::cin >> b1.x >> b1.y >> b2.x >> b2.y;

  std::cout << OverlappingArea(a1, a2, b1, b2);

  return 0;
}