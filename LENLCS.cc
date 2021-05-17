// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int LCSLength(const std::string& a, const std::string& b) {
  const int m{static_cast<int>(a.size())};
  const int n{static_cast<int>(b.size())};

  std::vector<std::vector<int>> lcs(m + 1, std::vector<int>(n + 1));

  for (int i{0}; i < m + 1; ++i) {
    for (int j{0}; j < n + 1; ++j) {
      if (i == 0 || j == 0) {
        lcs[i][j] = 0;
      } else if (a[i - 1] == b[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      } else {
        lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
  }

  return lcs[m][n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int d;
  std::cin >> d;

  std::string u, v;
  while (--d >= 0) {
    int n, m;
    std::cin >> n;
    u.reserve(n);
    std::cin >> u;

    std::cin >> m;
    v.reserve(m);
    std::cin >> v;

    std::cout << LCSLength(u, v) << "\n";
  }

  return 0;
}