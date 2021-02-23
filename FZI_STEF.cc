// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  long long max_profit{0};
  long long current_profit{0};
  while (--n >= 0) {
    int profit;
    std::cin >> profit;

    current_profit += profit;
    if (current_profit < 0) {
      current_profit = 0;
    } else if (current_profit > max_profit) {
      max_profit = current_profit;
    }
  }

  std::cout << max_profit;

  return 0;
}