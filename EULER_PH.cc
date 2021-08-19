// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int Phi(int n) {
  int result{n};

  const int bound{static_cast<int>(std::sqrt(n))};
  for (int i{2}; i <= bound; ++i) {
    if (n % i == 0) {
      do n /= i;
      while (n % i == 0);
      result -= result / i;
    }
  }

  if (n > 1) result -= result / n;
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  int n;
  while (--t >= 0) {
    std::cin >> n;
    std::cout << Phi(n) << "\n";
  }

  return 0;
}