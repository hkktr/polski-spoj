// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int s;
    std::cin >> s;

    int n{0};
    while (s != 1) {
      if (s % 2) {
        s = 3 * s + 1;
      } else {
        s = s / 2;
      }
      ++n;
    }
    std::cout << n << "\n";
  }

  return 0;
}