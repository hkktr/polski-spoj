// C++ (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const auto LessStringNumber{
    [](const std::string& lhs, const std::string& rhs) -> bool {
      if (lhs.size() < rhs.size() || (lhs.size() == rhs.size() && lhs < rhs))
        return true;
      return false;
    }};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::string> numbers;
  numbers.reserve(n);

  std::string number;
  while (--n >= 0) {
    std::cin >> number;
    numbers.push_back(number);
  }

  std::sort(numbers.begin(), numbers.end(), LessStringNumber);

  int k;
  std::cin >> k;

  while (--k >= 0) {
    std::cin >> number;
    std::cout << std::distance(numbers.begin(),
                               std::lower_bound(numbers.begin(), numbers.end(),
                                                number, LessStringNumber))
              << "\n";
  }

  return 0;
}