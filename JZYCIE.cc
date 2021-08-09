// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

bool GetSimulationResult(std::vector<std::vector<char>> board) {
  std::vector<std::vector<char>> board_temp(5, std::vector<char>(5));
  int time{100};

  while (--time >= 0) {
    int y0{4};
    for (int i{0}; i < 5; ++i, ++y0) {
      y0 %= 5;
      int x0{4};

      for (int j{0}; j < 5; ++j, ++x0) {
        x0 %= 5;
        int environment{0};

        for (int y_offset{0}; y_offset < 3; ++y_offset) {
          for (int x_offset{0}; x_offset < 3; ++x_offset) {
            const int x{(x0 + x_offset) % 5};
            const int y{(y0 + y_offset) % 5};

            if (x == j && y == i) continue;
            if (board[y][x] == '1') ++environment;
          }
        }

        if (environment < 2 || environment > 3) {
          board_temp[i][j] = '0';
        } else if (environment == 2) {
          board_temp[i][j] = board[i][j];
        } else if (environment == 3) {
          board_temp[i][j] = '1';
        }
      }
    }

    board_temp.swap(board);
  }

  for (const std::vector<char>& row : board) {
    for (char cell : row) {
      if (cell == '1') return true;
    }
  }
  return false;
}

std::vector<std::vector<char>> ReadBoard() {
  std::vector<std::vector<char>> board(5, std::vector<char>(5));

  for (std::vector<char>& row : board) {
    for (char& cell : row) {
      std::cin >> cell;
    }
  }

  return board;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (--n >= 0) {
    const std::vector<std::vector<char>> board{ReadBoard()};
    std::cout << (GetSimulationResult(board) ? "yes" : "no") << "\n";
  }

  return 0;
}