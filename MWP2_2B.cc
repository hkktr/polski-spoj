// C++14 (gcc 8.3)
#include <iostream>

int PowerModulo(int base, int exponent, int n) {
  base %= n;
  if (base == 0) return 0;

  int result{1};
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = result * base % n;
    }
    exponent /= 2;
    base = base * base % n;
  }

  return result;
}

int main() {
  int u, s, d;
  while (std::cin >> u >> s >> d) {
    if (u == 0 && s == 0 && d == 0) break;
    std::cout << PowerModulo(u, s, d) << "\n";
  }

  return 0;
}