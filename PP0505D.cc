// C++14 (gcc 8.3)
#include <iostream>

void Gray(int n, int* array, int k = 0, char direction = 1) {
  if (n == k) {
    for (int i{0}; i < k; ++i) {
      std::cout << array[i];
    }
    std::cout << "\n";
  } else {
    if (direction == 1) {
      array[k] = 0;
    } else {
      array[k] = 1;
    }
    Gray(n, array, k + 1, 1);

    if (direction == 1) {
      array[k] = 1;
    } else {
      array[k] = 0;
    }
    Gray(n, array, k + 1, 0);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    int* array{new int[n]{0}};
    Gray(n, array);
    delete[] array;
  }

  return 0;
}