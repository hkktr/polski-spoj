// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    int sum{0};
    while (--n >= 0) {
      int number;
      std::cin >> number;
      sum += number;
    }

    std::cout << sum << "\n";
  }

  return 0;
}