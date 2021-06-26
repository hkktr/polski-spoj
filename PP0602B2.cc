// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

void PrintTable(const std::vector<std::vector<int>>& table) {
  for (const std::vector<int>& row : table) {
    for (int number : row) {
      std::cout << number << " ";
    }
    std::cout << "\n";
  }
}

std::vector<std::vector<int>> GetTable(int n, int m) {
  std::vector<std::vector<int>> table(n, std::vector<int>(m));
  for (std::vector<int>& row : table) {
    for (int& number : row) {
      std::cin >> number;
    }
  }
  return table;
}

void TransmuteTable(std::vector<std::vector<int>>& table) {
  const int n{static_cast<int>(table.size())};
  const int m{static_cast<int>(table[0].size())};

  int last{table[0][0]};
  table[0][0] = m % 2 == 1 ? table[n - 1][m - 1] : table[0][m - 1];

  for (int column{0}; column < m; ++column) {
    if (column % 2 == 0) {
      for (int row{1}; row < n; ++row) std::swap(last, table[row][column]);

      if (column != m - 1) {
        std::swap(last, table[n - 1][column + 1]);
      }
    } else {
      for (int row{n - 2}; row >= 0; --row) std::swap(last, table[row][column]);

      if (column != m - 1) {
        std::swap(last, table[0][column + 1]);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int l, k;
    std::cin >> l >> k;

    std::vector<std::vector<int>> table{GetTable(l, k)};
    TransmuteTable(table);
    PrintTable(table);
  }

  return 0;
}