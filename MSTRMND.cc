// C++14 (gcc 8.3)
#include <algorithm>
#include <array>
#include <iostream>

int main() {
  std::array<int, 4> answer{1};
  std::array<int, 4> hint{0};

  for (int i{0}; i < 6; ++i) {
    if (std::all_of(hint.begin(), hint.end(), [](int n) { return n == 1; })) {
      break;
    }

    for (int j{0}; j < 4; ++j) {
      std::cout << i + 1 << " ";
    }
    std::cout << "\n";
    std::fflush(stdout);

    for (int& hint_number : hint) {
      std::cin >> hint_number;
    }

    for (int j{0}; j < 4; ++j) {
      if (hint[j] == 1) {
        answer[j] = i + 1;
      }
    }
  }

  for (int answer_number : answer) {
    std::cout << answer_number << " ";
  }
  std::cout << "\n";
  std::fflush(stdout);

  return 0;
}