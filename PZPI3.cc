// C++14 (gcc 8.3)
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> GetSquaredPrimes(int max) {
  const int bound{static_cast<int>(std::sqrt(max))};

  std::vector<char> is_prime(bound + 1, true);
  std::vector<int> squared_primes;

  for (int i{2}; i <= bound; ++i) {
    if (is_prime[i]) {
      squared_primes.push_back(i * i);
      for (int j{i * i}; j <= bound; j += i) {
        is_prime[j] = false;
      }
    }
  }

  return squared_primes;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  constexpr int kMax{1'000'000'000};
  const std::vector<int> squared_primes{GetSquaredPrimes(kMax)};

  int t;
  std::cin >> t;

  int a, b;
  while (--t >= 0) {
    std::cin >> a >> b;

    const auto lower_bound{
        std::lower_bound(squared_primes.begin(), squared_primes.end(), a)};
    const auto upper_bound{
        std::upper_bound(squared_primes.begin(), squared_primes.end(), b)};

    std::cout << std::distance(lower_bound, upper_bound) << "\n";
  }

  return 0;
}