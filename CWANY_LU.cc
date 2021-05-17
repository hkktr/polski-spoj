// C++14 (gcc 8.3)
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int d;
  std::cin >> d;

  while (--d >= 0) {
    int n, k;
    std::cin >> n >> k;
    std::cout << ((n | k) == n ? "N" : "P") << "\n";
  }

  return 0;
}