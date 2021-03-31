// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;

  std::string word;
  word.reserve(n);
  std::cin >> word;

  for (int start{static_cast<int>(word.size() / 2)}, length{1}; start >= 0;
       --start, length += 2) {
    for (int i{0}; i < start; ++i) {
      std::cout << ".";
    }
    for (int i{start}; i < start + length; ++i) {
      std::cout << word[i];
    }
    for (int i{start + length}; i < static_cast<int>(word.size()); ++i) {
      std::cout << ".";
    }
    std::cout << "\n";
  }

  return 0;
}