// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    int* array{new int[n]};
    for (int i{0}; i < n; ++i) {
      std::cin >> array[i];
    }

    for (int i{1}; i < n; ++i) {
      std::cout << array[i] << " ";
    }
    std::cout << array[0] << "\n";

    delete[] array;
  }

  return 0;
}