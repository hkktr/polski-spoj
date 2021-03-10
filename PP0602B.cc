// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

using table_t = std::vector<std::vector<int>>;

void TurnFrameLeft(table_t& table) {
  const std::size_t rows{table.size()}, cols{table[0].size()};
  const int temp{table[0][0]};

  for (std::size_t i{0}; i < cols - 1; ++i) {
    table[0][i] = table[0][i + 1];
  }
  for (std::size_t i{0}; i < rows - 1; ++i) {
    table[i][cols - 1] = table[i + 1][cols - 1];
  }
  for (std::size_t i{cols - 1}; i > 0; --i) {
    table[rows - 1][i] = table[rows - 1][i - 1];
  }
  for (std::size_t i{rows - 1}; i > 1; --i) {
    table[i][0] = table[i - 1][0];
  }

  table[1][0] = temp;
}

void PrintTable(const table_t& table) {
  for (std::size_t i{0}, m{table.size()}; i < m; ++i) {
    for (std::size_t j{0}, n{table[i].size()}; j < n; ++j) {
      std::cout << table[i][j] << " ";
    }
    std::cout << "\n";
  }
}

table_t GetTable(std::size_t m, std::size_t n) {
  table_t table(m, std::vector<int>(n));

  for (std::size_t i{0}; i < m; ++i) {
    for (std::size_t j{0}; j < n; ++j) {
      std::cin >> table[i][j];
    }
  }

  return table;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    std::size_t l, k;
    std::cin >> l >> k;

    table_t table{GetTable(l, k)};
    TurnFrameLeft(table);
    PrintTable(table);
  }

  return 0;
}