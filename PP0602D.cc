// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  int* numbers{new int[n]};
  for (int i{0}; i < n; ++i) {
    std::cin >> numbers[i];
  }

  for (int i{k}; i < n; ++i) {
    std::cout << numbers[i] << " ";
  }
  for (int i{0}; i < k; ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << "\n";
  delete[] numbers;

  return 0;
}