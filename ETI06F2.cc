// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int HighestPowerOf2(int n) {
  const int exponent{static_cast<int>(std::log2(n))};
  return static_cast<int>(std::pow(2, exponent));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int k;
  std::cin >> k;

  const int highest_power_of_2{HighestPowerOf2(k + 1)};
  const int number{k - highest_power_of_2 + 1};
  const int size{static_cast<int>(std::log2(highest_power_of_2 - 1))};

  for (int i{size}; i >= 0; --i) {
    std::cout << ((number & (1 << i)) ? "6" : "5");
  }
  std::cout << "\n";

  return 0;
}