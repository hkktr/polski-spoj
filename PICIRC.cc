// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

class Point {
 public:
  Point(int x = 0, int y = 0) : x_{x}, y_{y} {};

  double DistanceToPoint(const Point& other) {
    return std::sqrt(std::pow(other.x_ - x_, 2) + std::pow(other.y_ - y_, 2));
  }

  friend std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.x_ >> point.y_;
    return in;
  }

 private:
  int x_;
  int y_;
};

int main() {
  Point circle_center;
  std::cin >> circle_center;
  int circle_radius;
  std::cin >> circle_radius;

  int n;
  std::cin >> n;

  Point point;
  while (--n >= 0) {
    std::cin >> point;

    const double distance{circle_center.DistanceToPoint(point)};
    if (distance < circle_radius) {
      std::cout << "I";
    } else if (distance == circle_radius) {
      std::cout << "E";
    } else if (distance > circle_radius) {
      std::cout << "O";
    }
    std::cout << "\n";
  }

  return 0;
}