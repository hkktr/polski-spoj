// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    int x;
    std::cin >> x;
    std::cout << x * x << "\n";
  }

  return 0;
}