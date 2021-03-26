// C++14 (gcc 8.3)
#include <array>
#include <cmath>
#include <iostream>
#include <string>

int main() {
  std::array<int, 21> numbers{0};
  int input;
  while (std::cin >> input) {
    ++numbers[input + 10];
  }

  int max_number{0};
  for (auto it{numbers.begin()}; it != numbers.end(); ++it) {
    if (*it > max_number) max_number = *it;
  }

  constexpr int kWidth{30};
  if (max_number > 0) {
    for (int i{-10}; i <= 10; ++i) {
      std::cout << std::string(4 - std::to_string(i).size(), ' ') << i << ":|";

      const int width{static_cast<int>(std::round(
          kWidth * numbers[i + 10] / static_cast<double>(max_number)))};
      for (int j{0}; j < kWidth; ++j) {
        if (j < width) {
          std::cout << "*";
        } else {
          std::cout << " ";
        }
      }

      std::cout << "|\n";
    }
  }

  return 0;
}