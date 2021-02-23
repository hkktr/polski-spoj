// C++14 (gcc 8.3)
#include <iostream>

long BinomialCoefficient(int n, int k) {
  if (k > n - k) k = n - k;

  long result{1};
  for (int i{0}; i < k; ++i) {
    result *= n - i;
    result /= i + 1;
  }

  return result;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n, k;
    std::cin >> n >> k;
    std::cout << BinomialCoefficient(n, k) << "\n";
  }

  return 0;
}