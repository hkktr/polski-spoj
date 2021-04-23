// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

bool IsPerfectSquare(int square) {
  if (square > 0) {
    const int square_root{static_cast<int>(std::sqrt(square))};
    return std::pow(square_root, 2) == square;
  }
  return false;
}

int main() {
  int n;
  std::cin >> n;

  int square;
  while (--n >= 0) {
    std::cin >> square;
    std::cout << (IsPerfectSquare(square) ? "TAK" : "NIE") << "\n";
  }

  return 0;
}