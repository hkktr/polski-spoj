// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int x, y, z;
  std::cin >> x >> y >> z;

  while (--n) {
    int a, b, c;
    std::cin >> a >> b >> c;

    const int temp_x{a + std::min(y, z)};
    const int temp_y{b + std::min(x, z)};
    const int temp_z{c + std::min(x, y)};

    x = temp_x;
    y = temp_y;
    z = temp_z;
  }

  std::cout << std::min(x, std::min(y, z)) << "\n";

  return 0;
}