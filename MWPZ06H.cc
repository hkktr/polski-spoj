// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    std::size_t n;
    std::cin >> n;

    std::vector<int> points(n);
    for (std::size_t i{0}; i < n; ++i) {
      std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    std::size_t best_index{points.size()};
    do {
      std::cout << points[--best_index] << " ";
    } while (best_index > 0 && points[best_index - 1] == points[best_index]);

    for (std::size_t i{0}; i < best_index; ++i) {
      std::cout << points[i] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}