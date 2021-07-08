// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n, a, b;
    std::cin >> n >> a >> b;

    n = (n - 1) % 60 + 1;
    std::vector<int> pisano_period(n);
    pisano_period[0] = a % 10, pisano_period[1] = b % 10;

    for (int i{2}; i < n; ++i) {
      pisano_period[i] = (pisano_period[i - 2] + pisano_period[i - 1]) % 10;
    }

    std::cout << pisano_period[n - 1] << "\n";
  }

  return 0;
}