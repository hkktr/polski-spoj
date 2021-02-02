// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  int m, n;
  std::cin >> m >> n;

  std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
  for (int i{0}; i < m; ++i) {
    for (int j{0}; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      std::cout << matrix[j][i] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}