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

int LCM(int a, int b) { return (a * b) / GCD(a, b); }

int main() {
  int n;
  std::cin >> n;

  while (--n >= 0) {
    int a, b;
    std::cin >> a >> b;
    std::cout << LCM(a, b) << "\n";
  }

  return 0;
}