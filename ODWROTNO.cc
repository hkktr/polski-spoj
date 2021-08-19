// C++ (gcc 8.3)
#include <iostream>
#include <tuple>

std::tuple<int, int, int> ExtendedGCD(int a, int b) {
  if (a == 0) return std::make_tuple(0, 1, b);

  int x, y, gcd;
  std::tie(x, y, gcd) = ExtendedGCD(b % a, a);

  return std::make_tuple(y - (b / a) * x, x, gcd);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  int p, n;
  while (--t >= 0) {
    std::cin >> p >> n;

    int y{std::get<1>(ExtendedGCD(p, n))};
    if (y < 0) y -= ((y - p + 1) / p) * p;
    std::cout << y << "\n";
  }

  return 0;
}