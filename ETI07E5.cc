// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> x_coordinates;
  x_coordinates.reserve(n);
  long long total_distance{0};
  while (--n >= 0) {
    int x, y;
    std::cin >> x >> y;

    x_coordinates.push_back(x);
    total_distance += std::abs(y);
  }

  std::nth_element(x_coordinates.begin(),
                   x_coordinates.begin() + (x_coordinates.size() - 1) / 2,
                   x_coordinates.end());
  const int x_centroid{x_coordinates[(x_coordinates.size() - 1) / 2]};

  for (int x : x_coordinates) {
    total_distance += std::abs(x - x_centroid);
  }

  std::cout << x_centroid << " " << total_distance << "\n";

  return 0;
}