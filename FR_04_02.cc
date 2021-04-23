// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int q;
  std::cin >> q;

  while (--q >= 0) {
    int n, k;
    std::cin >> n >> k;

    if (n % 2 != 0) {
      std::cout << "BRAK\n";
    } else {
      if (k > n / 2) {
        std::cout << k - n / 2 << "\n";
      } else {
        std::cout << k + n / 2 << "\n";
      }
    }
  }

  return 0;
}