// C++14 (gcc 8.3)
#include <iostream>

using ll_t = long long;

ll_t Determiner(ll_t x1, ll_t y1, ll_t x2, ll_t y2, ll_t x3, ll_t y3) {
  return x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - y3 * x1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (true) {
    int x1, y1, x2, y2, x3, y3, x, y;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
    if (x1 == 0) break;

    const ll_t determiner{Determiner(x1, y1, x2, y2, x3, y3)};
    ll_t determiner_a{Determiner(x1, y1, x2, y2, x, y)};
    ll_t determiner_b{Determiner(x2, y2, x3, y3, x, y)};
    ll_t determiner_c{Determiner(x3, y3, x1, y1, x, y)};

    if ((determiner_a == 0 && determiner_b == 0) ||
        (determiner_b == 0 && determiner_c == 0) ||
        (determiner_c == 0 && determiner_a == 0)) {
      std::cout << "E\n";
    } else if (determiner_a == 0 || determiner_b == 0 || determiner_c == 0) {
      if (determiner_a == 0) determiner_a = 1;
      if (determiner_b == 0) determiner_b = 1;
      if (determiner_c == 0) determiner_c = 1;

      if (determiner_a * determiner_b * determiner_c > 0) {
        std::cout << "E\n";
      } else {
        std::cout << "O\n";
      }
    } else {
      if (determiner > 0) {
        if (determiner_a > 0 && determiner_b > 0 && determiner_c > 0) {
          std::cout << "I\n";
        } else {
          std::cout << "O\n";
        }
      } else {
        if (determiner_a < 0 && determiner_b < 0 && determiner_c < 0) {
          std::cout << "I\n";
        } else {
          std::cout << "O\n";
        }
      }
    }
  }

  return 0;
}