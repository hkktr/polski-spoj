// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    int* const numbers{new int[n]};
    int sum{0};
    for (int i{0}; i < n; ++i) {
      std::cin >> numbers[i];
      sum += numbers[i];
    }

    const double average{static_cast<double>(sum) / n};
    double min_difference{std::abs(average - numbers[0])};
    int min_difference_index{0};
    for (int i{1}; i < n; ++i) {
      const double difference{std::abs(average - numbers[i])};
      if (difference < min_difference) {
        min_difference = difference;
        min_difference_index = i;
      }
    }

    std::cout << numbers[min_difference_index] << "\n";
    delete[] numbers;
  }

  return 0;
}