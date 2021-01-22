// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n, x, y;
    std::cin >> n >> x >> y;

    for (int i{x}; i < n; i += x) {
      if (i % y != 0) {
        std::cout << i << " ";
      }
    }
    std::cout << "\n";
  }

  return 0;
}