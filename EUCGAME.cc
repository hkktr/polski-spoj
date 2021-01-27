// C++14 (gcc 8.3)
#include <iostream>

int GCD(int a, int b) {
  while (b != 0) {
    const int temp{b};
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int a, b;
    std::cin >> a >> b;
    std::cout << GCD(a, b) * 2 << "\n";
  }

  return 0;
}