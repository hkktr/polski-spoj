// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  unsigned long long number;
  while (std::cin >> number) {
    std::vector<int> binary;
    while (number != 0) {
      binary.push_back(number % 2);
      number /= 2;
    }

    unsigned long long result{0};
    unsigned long long weight{1};
    for (auto it{binary.rbegin()}; it != binary.rend(); ++it) {
      result += *it * weight;
      weight *= 2;
    }

    std::cout << result << "\n";
  }

  return 0;
}