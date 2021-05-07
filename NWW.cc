// C++14 (gcc 8.3)
#include <iostream>

using ull_t = unsigned long long;

constexpr ull_t GCD(ull_t a, ull_t b) {
  while (b != 0) {
    ull_t temp{b};
    b = a % b;
    a = temp;
  }

  return a;
}

constexpr ull_t LCM(ull_t a, ull_t b) { return a * (b / GCD(a, b)); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;
    if (n == 0) continue;

    ull_t result;
    std::cin >> result;

    while (--n > 0) {
      ull_t number;
      std::cin >> number;
      result = LCM(result, number);
    }

    std::cout << result << "\n";
  }

  return 0;
}