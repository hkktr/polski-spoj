// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    int* numbers{new int[n]};
    for (int i{0}; i < n; ++i) {
      std::cin >> numbers[i];
    }

    for (int i{1}; i < n; i += 2) {
      std::cout << numbers[i] << " ";
    }
    for (int i{0}; i < n; i += 2) {
      std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    delete[] numbers;
  }

  return 0;
}