// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

long long FactorsSum(int n) {
  long long result{1};
  for (int i{2}; i <= static_cast<int>(std::sqrt(n)); ++i) {
    int current_sum{1};
    int current_term{1};

    while (n % i == 0) {
      n /= i;
      current_term *= i;
      current_sum += current_term;
    }

    result *= current_sum;
  }

  if (n >= 2) result *= (1 + static_cast<long long>(n));
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
    std::cout << FactorsSum(n) << "\n";
  }

  return 0;
}