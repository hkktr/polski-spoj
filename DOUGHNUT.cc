// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int c, k, w;
    std::cin >> c >> k >> w;
    std::cout << ((c * w <= k) ? "yes" : "no") << "\n";
  }

  return 0;
}