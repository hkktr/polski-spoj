// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  int z;
  std::cin >> z;

  std::vector<int> numbers;
  while (--z >= 0) {
    int m;
    std::cin >> m;

    numbers.resize(m);
    int sum_left{0};
    for (int& number : numbers) {
      std::cin >> number;
      sum_left += number;
    }

    int i{0};
    int sum_right{0};
    for (i; i < m - 1; ++i) {
      sum_left -= numbers[i];
      sum_right += numbers[i];
      if (sum_left == sum_right) break;
    }

    if (i == m - 1) {
      std::cout << "0\n";
    } else {
      std::cout << i + 1 << "\n";
    }
  }

  return 0;
}