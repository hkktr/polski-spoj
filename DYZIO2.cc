// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

void ErastotenesPrimesCount(std::vector<int>& primes_count) {
  for (int i{2}; i * i <= 1'000'001; ++i) {
    if (primes_count[i]) continue;

    primes_count[i] = i;

    for (int j{i * i}; j <= 1'000'001; j += i) {
      if (!primes_count[j]) primes_count[j] = i;
    }
  }

  for (int i{2}, result{0}; i <= 1'000'001; ++i) {
    if (primes_count[i] == i || !primes_count[i]) ++result;
    primes_count[i] = result;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<int> primes_count(1'000'002);
  ErastotenesPrimesCount(primes_count);

  int n;
  std::cin >> n;

  while (--n >= 0) {
    int a, b;
    std::cin >> a >> b;
    std::cout << primes_count[b] - primes_count[a - 1] << "\n";
  }

  return 0;
}