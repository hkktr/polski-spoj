// C++14 (gcc 8.3)
#include <iostream>
#include <string>

bool IsPalindrome(const std::string& text) {
  for (unsigned i{0}; i < text.size() / 2; ++i) {
    if (text[0] != text[text.size() - 1]) return false;
  }
  return true;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    std::string number;
    std::cin >> number;

    int n{0};
    while (!IsPalindrome(number)) {
      number = std::to_string(
          std::stoi(number) +
          std::stoi(std::string{number.rbegin(), number.rend()}));
      ++n;
    }
    std::cout << number << " " << n << "\n";
  }

  return 0;
}