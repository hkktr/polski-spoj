// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    int pupils, sweets;
    std::cin >> pupils >> sweets;

    if (pupils != 1 && sweets % (pupils - 1) == 0) {
      std::cout << "NIE\n";
    } else {
      std::cout << "TAK\n";
    }
  }

  return 0;
}