// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << 2 * v1 * v2 / (v1 + v2) << "\n";
  }

  return 0;
}