// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  long* array{new long[n]};
  for (int i{0}; i < n; ++i) {
    std::cin >> array[i];
  }

  char condition_operator;
  std::cin >> condition_operator;
  long condition_value;
  std::cin >> condition_value;

  for (int i{0}; i < n; ++i) {
    if (condition_operator == '<' && array[i] < condition_value) {
      std::cout << array[i] << "\n";
    } else if (condition_operator == '>' && array[i] > condition_value) {
      std::cout << array[i] << "\n";
    }
  }
  delete[] array;

  return 0;
}