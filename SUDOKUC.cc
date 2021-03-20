// C++14 (gcc 8.3)
#include <array>
#include <iostream>

bool IsValidSudoku(const std::array<std::array<int, 9>, 9>& sudoku_grid) {
  std::array<bool, 9> used;

  for (std::size_t i{0}; i < 9; ++i) {
    used.fill(false);

    for (std::size_t j{0}; j < 9; ++j) {
      const int value{sudoku_grid[i][j]};
      if (value < 0 || value > 9 || used[value - 1]) return false;
      used[value - 1] = true;
    }
  }

  for (std::size_t i{0}; i < 9; ++i) {
    used.fill(false);

    for (std::size_t j{0}; j < 9; ++j) {
      const int value{sudoku_grid[j][i]};
      if (used[value - 1]) return false;
      used[value - 1] = true;
    }
  }

  for (std::size_t i_start{0}; i_start < 9; i_start += 3) {
    for (std::size_t j_start{0}; j_start < 9; j_start += 3) {
      used.fill(false);

      for (std::size_t i{0}; i < 3; ++i) {
        for (std::size_t j{0}; j < 3; ++j) {
          const int value{sudoku_grid[i_start + i][j_start + j]};
          if (used[value - 1]) return false;
          used[value - 1] = true;
        }
      }
    }
  }

  return true;
}

std::array<std::array<int, 9>, 9> GetSudokuGrid() {
  std::array<std::array<int, 9>, 9> sudoku_grid;
  for (std::size_t i{0}; i < 9; ++i) {
    for (std::size_t j{0}; j < 9; ++j) {
      std::cin >> sudoku_grid[i][j];
    }
  }

  return sudoku_grid;
}

int main() {
  int n;
  std::cin >> n;

  while (--n >= 0) {
    std::array<std::array<int, 9>, 9> sudoku_grid{GetSudokuGrid()};
    std::cout << (IsValidSudoku(sudoku_grid) ? "TAK" : "NIE") << "\n";
  }

  return 0;
}