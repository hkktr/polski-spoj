// C++14 (gcc 8.3)
#include <array>
#include <iostream>

int LastNon0Digit(int n) {
  constexpr std::array<int, 10> kDigits{1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

  if (n < 10) return kDigits[n];

  if (((n / 10) % 10) % 2 == 0) {
    return (6 * LastNon0Digit(n / 5) * kDigits[n % 10]) % 10;
  } else {
    return (4 * LastNon0Digit(n / 5) * kDigits[n % 10]) % 10;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;
    std::cout << LastNon0Digit(n) << "\n";
  }

  return 0;
}