// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  int k, n;
  std::cin >> k >> n;

  std::vector<long long> a(k), b(k);
  while (--n >= 0) {
    for (long long& coord : a) {
      std::cin >> coord;
    }
    for (long long& coord : b) {
      std::cin >> coord;
    }

    long long distance{0};
    for (std::size_t i{0}; i < a.size(); ++i) {
      distance += std::abs(a[i] - b[i]);
    }
    std::cout << distance << "\n";
  }

  return 0;
}