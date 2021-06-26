// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int MaxTents(int n, int a, int b, const std::vector<int>& costs_a,
             const std::vector<int>& costs_b) {
  std::vector<std::vector<std::vector<int>>> max_tents(
      n + 1, std::vector<std::vector<int>>(a + 1, std::vector<int>(b + 1, 0)));

  for (int k{1}; k <= n; ++k) {
    for (int i{1}; i <= a; ++i) {
      for (int j{1}; j <= b; ++j) {
        if (i >= costs_a[k - 1] && j >= costs_b[k - 1]) {
          max_tents[k][i][j] = std::max(
              1 + max_tents[k - 1][i - costs_a[k - 1]][j - costs_b[k - 1]],
              max_tents[k - 1][i][j]);
        } else {
          max_tents[k][i][j] = max_tents[k - 1][i][j];
        }
      }
    }
  }

  return max_tents[n][a][b];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, a, b;
  std::cin >> n >> a >> b;

  std::vector<int> costs_a(n), costs_b(n);
  for (int i{0}; i < n; ++i) {
    std::cin >> costs_a[i] >> costs_b[i];
  }

  std::cout << MaxTents(n, a, b, costs_a, costs_b) << "\n";

  return 0;
}