// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

void PrintFan(const std::vector<std::vector<char>>& fan) {
  for (std::size_t i{0}; i < fan.size(); ++i) {
    for (std::size_t j{0}; j < fan[i].size(); ++j) {
      std::cout << fan[i][j];
    }
    std::cout << "\n";
  }
}

void ReverseFan(std::vector<std::vector<char>>& fan) {
  for (std::size_t i{0}; i < fan.size(); ++i) {
    for (std::size_t j{0}; j < fan[i].size() / 2; ++j) {
      std::swap(fan[i][j], fan[i][fan[i].size() - 1 - j]);
    }
  }
}

void DrawFan(int r) {
  const std::size_t size{static_cast<std::size_t>(std::abs(r))};
  std::vector<std::vector<char>> fan(2 * size,
                                     std::vector<char>(2 * size, '*'));

  for (std::size_t i{0}; i < size; ++i) {
    for (std::size_t j{i + 1}; j < size; ++j) {
      fan[i][j] = '.';
    }
    for (std::size_t j{2 * size - 1}; j > 2 * size - 1 - i; --j) {
      fan[i][j] = '.';
    }
  }

  for (std::size_t i{size}; i < 2 * size; ++i) {
    for (std::size_t j{0}; j < 2 * size; ++j) {
      fan[i][j] = fan[size - 1 - (i - size)][2 * size - 1 - j];
    }
  }

  if (r < 0) ReverseFan(fan);
  PrintFan(fan);
}

int main() {
  while (true) {
    int r;
    std::cin >> r;

    if (r == 0) break;
    DrawFan(r);
  }

  return 0;
}