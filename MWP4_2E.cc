// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  int z;
  std::cin >> z;

  while (--z >= 0) {
    int i, j, k;
    std::cin >> i >> j >> k;

    std::vector<bool> people(i, false);
    people[k - 1] = true;
    std::cout << k << " ";

    while (--j >= 0) {
      int a, b;
      std::cin >> a >> b;

      if (people[a - 1] && !people[b - 1]) {
        people[b - 1] = true;
        std::cout << b << " ";
      }
    }

    std::cout << "\n";
  }

  return 0;
}