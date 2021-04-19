// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  int left_age, left_position;
  int right_age, right_position;
  while (--t >= 0) {
    std::cin >> left_age >> left_position;
    std::cin >> right_age >> right_position;

    if (left_age > right_age) {
      if ((std::abs(right_position - left_position) + 1) % 3 == 2) {
        std::cout << "0\n";
      } else {
        std::cout << "1\n";
      }
    } else {
      if ((std::abs(right_position - left_position) + 1) % 3 == 2) {
        std::cout << "1\n";
      } else {
        std::cout << "0\n";
      }
    }
  }

  return 0;
}