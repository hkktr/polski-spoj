// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::string elevator_movement;
    std::cin >> elevator_movement;

    int min{0}, max{0};
    int y{0};
    for (char move : elevator_movement) {
      if (move == 'U') {
        ++y;
        if (y > max) {
          max = y;
          if (max - min + 1 > n) break;
        }
      } else if (move == 'D') {
        --y;
        if (y < min) {
          min = y;
          if (max - min + 1 > n) break;
        }
      }
    }

    std::cout << (max - min + 1 > n ? "NIE" : "TAK") << "\n";
  }

  return 0;
}