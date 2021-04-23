// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>

int main() {
  int z;
  std::cin >> z;
  std::cin.ignore();

  while (--z >= 0) {
    char last{'A'}, next{'\0'};
    int result{0};
    while ((next = static_cast<char>(std::getchar())) != '\n' && next != EOF) {
      result += std::min(
          std::abs(next - last),
          std::min(last - 'A', 'Z' - last) +
              std::min(std::abs(next - 'A'), std::abs(next - 'Z')) + 1);
      last = next;
    }

    std::cout << result << "\n";
  }

  return 0;
}