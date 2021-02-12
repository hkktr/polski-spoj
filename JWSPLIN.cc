// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) == 0) {
      std::cout << "TAK\n";
    } else {
      std::cout << "NIE\n";
    }
  }

  return 0;
}