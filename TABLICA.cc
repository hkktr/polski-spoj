// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  int number;
  while (std::cin >> number) {
    numbers.push_back(number);
  }

  for (auto i{numbers.rbegin()}; i != numbers.rend(); ++i) {
    std::cout << *i << " ";
  }

  return 0;
}