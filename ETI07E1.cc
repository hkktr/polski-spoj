// C++14 (gcc 8.3)
#include <array>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::array<bool, 52> cards{false};

  int card_number;
  for (int i{0}; i < 26; ++i) {
    std::cin >> card_number;
    cards[card_number - 1] = true;
  }

  int a{51}, b{51};
  int wins{0};
  while (a >= 0 && b >= 0) {
    while (a >= 0 && !cards[a]) --a;
    b = std::min(a, b);
    while (b >= 0 && cards[b]) --b;

    if (a >= 0 && b >= 0) ++wins;

    --a;
    --b;
  }

  std::cout << wins << "\n";

  return 0;
}