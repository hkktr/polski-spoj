// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

std::vector<int> EratosthenesSieve(int max) {
  std::vector<int> sieve(std::max(3, max) + 1);
  sieve[0] = 1;
  sieve[1] = 1;
  sieve[2] = 2;

  for (int i{4}; i <= max; i += 2) {
    if (!sieve[i]) sieve[i] = 2;
  }

  for (int i{3}; i * i <= max; i += 2) {
    if (sieve[i]) continue;

    sieve[i] = i;
    for (int j{i * i}; j <= max; j += i) {
      if (!sieve[j]) sieve[j] = i;
    }
  }

  for (int i{3}; i <= max; i += 2) {
    if (!sieve[i]) sieve[i] = i;
  }

  return sieve;
}

int GCD(int a, int b) {
  while (b != 0) {
    int temp{b};
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int z;
  std::cin >> z;

  std::vector<int> a(z), b(z);
  int max{-1};
  for (int i{0}; i < z; ++i) {
    std::cin >> a[i] >> b[i];
    if (a[i] == b[i]) max = std::max(a[i], max);
  }

  const std::vector<int> primes_sieve{EratosthenesSieve(max)};
  for (int i{0}; i < z; ++i) {
    if (a[i] == b[i]) {
      std::cout << a[i] / primes_sieve[a[i]] << "\n";
    } else {
      std::cout << GCD(a[i], b[i]) << "\n";
    }
  }

  return 0;
}