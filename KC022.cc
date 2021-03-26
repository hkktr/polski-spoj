// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int i;
  while (std::cin >> i) {
    std::vector<int> sequence;
    while (std::cin.peek() != '\n') {
      int number;
      std::cin >> number;
      sequence.push_back(number);
    }

    std::sort(sequence.rbegin(), sequence.rend());
    sequence.erase(std::unique(sequence.begin(), sequence.end()),
                   sequence.end());

    if (static_cast<int>(sequence.size()) < i) {
      std::cout << "-\n";
    } else {
      std::cout << sequence[i - 1] << "\n";
    }
  }

  return 0;
}