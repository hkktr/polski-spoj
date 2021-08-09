// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::vector<int> readings;
    readings.reserve(n);

    int max_speed{0};
    int reading;
    for (int i{0}; i < n; ++i) {
      std::cin >> reading;
      readings.push_back(reading);
      max_speed += reading;
    }

    const int search_speed{max_speed / 2};
    std::vector<int> knapsack(search_speed + 1, 0);

    for (int k{0}; k < n; ++k) {
      const int i{readings[k]};
      for (int j{search_speed}; j >= i; --j) {
        knapsack[j] = std::max(i + knapsack[j - i], knapsack[j]);
      }
    }

    const int min_speed{std::abs(max_speed - 2 * knapsack[search_speed])};
    std::cout << min_speed << " " << max_speed << "\n";
  }

  return 0;
}