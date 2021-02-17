// C++14 (gcc 8.3)
#include <iostream>

int main() {
  long total_sum{0};
  long sum{0};
  int number;
  while (std::cin >> number) {
    if (number == 0) {
      std::cout << sum << "\n";
      total_sum += sum;
      sum = 0;
    } else {
      sum += number;
    }
  }

  std::cout << total_sum << "\n";

  return 0;
}