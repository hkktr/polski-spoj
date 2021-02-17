// C++14 (gcc 8.3)
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Point {
 public:
  Point(const std::string& name, int x, int y)
      : name_{name}, x_{x}, y_{y}, distance_to_origin_{DistanceToOrigin()} {}

  bool operator<(const Point& other) {
    return distance_to_origin_ < other.distance_to_origin_;
  }

  friend std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << point.name_ << " " << point.x_ << " " << point.y_;
    return out;
  }

 private:
  double DistanceToOrigin() {
    return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2));
  }

  std::string name_;
  int x_;
  int y_;

  double distance_to_origin_;
};

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::vector<Point> points;
    points.reserve(n);

    std::string name;
    int x, y;
    while (--n >= 0) {
      std::cin >> name >> x >> y;
      points.emplace_back(Point(name, x, y));
    }

    std::sort(points.begin(), points.end());
    for (const Point& point : points) {
      std::cout << point << "\n";
    }
  }

  return 0;
}