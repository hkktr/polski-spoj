// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n, pack_size;
    std::cin >> n >> pack_size;

    constexpr int kSecondsInADay{86400};
    int cookies_quantity{0};
    while (--n >= 0) {
      int eating_time;
      std::cin >> eating_time;
      cookies_quantity += kSecondsInADay / eating_time;
    }

    if (cookies_quantity % pack_size == 0) {
      std::cout << cookies_quantity / pack_size << "\n";
    } else {
      std::cout << cookies_quantity / pack_size + 1 << "\n";
    }
  }

  return 0;
}