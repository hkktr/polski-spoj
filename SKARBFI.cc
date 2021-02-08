// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    int n;
    std::cin >> n;

    int x{0}, y{0};
    while (--n >= 0) {
      int direction, steps;
      std::cin >> direction >> steps;

      switch (direction) {
        case 0:
          y += steps;
          break;
        case 1:
          y -= steps;
          break;
        case 2:
          x -= steps;
          break;
        case 3:
          x += steps;
          break;
      }
    }

    if (x == 0 && y == 0) {
      std::cout << "studnia\n";
    } else {
      if (y > 0) {
        std::cout << "0 " << std::abs(y) << "\n";
      } else if (y < 0) {
        std::cout << "1 " << std::abs(y) << "\n";
      }

      if (x < 0) {
        std::cout << "2 " << std::abs(x) << "\n";
      } else if (x > 0) {
        std::cout << "3 " << std::abs(x) << "\n";
      }
    }
  }

  return 0;
}