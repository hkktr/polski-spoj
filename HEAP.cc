// C++14 (gcc 8.3)
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::vector<int> numbers;
    numbers.reserve(n);

    int input_number;
    while (--n >= 0) {
      std::cin >> input_number;
      numbers.push_back(input_number);
    }

    std::make_heap(numbers.begin(), numbers.end(),
                   std::isgreaterequal<int, int>);

    std::cin >> n;
    while (--n >= 0) {
      char command;
      std::cin >> command;

      if (command == 'P') {
        for (int number : numbers) {
          std::cout << number << " ";
        }
        std::cout << "\n";
      } else if (command == 'E') {
        std::pop_heap(numbers.begin(), numbers.end(),
                      std::isgreaterequal<int, int>);
        std::cout << numbers.back() << "\n";
        numbers.pop_back();
      }
    }
  }

  return 0;
}