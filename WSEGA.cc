// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    int age{-1 + n};
    int new_legs;
    while (--n >= 0) {
      std::cin >> new_legs;
      age += new_legs;
    }

    std::cout << age << "\n";
  }

  return 0;
}