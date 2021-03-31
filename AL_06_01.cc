// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    int a, b;
    std::cin >> a >> b;
    
    if (a > 0 || a % b == 0) {
      std::cout << a % b << "\n";
    } else if (b < 0) {
      std::cout << a + (a / -b - 1) * b << "\n";
    } else if (b > 0) {
      std::cout << a - (a / b - 1) * b << "\n";
    }
  }

  return 0;
}