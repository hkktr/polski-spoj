// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::map<unsigned long long, int> number_frequency;
    for (int i{0}; i < n; ++i) {
      unsigned long long number;
      std::cin >> number;
      ++number_frequency[number];
    }

    const int min_number{n / 2};
    const auto found_number{std::find_if(
        number_frequency.begin(), number_frequency.end(),
        [min_number](const std::pair<unsigned long long, int>& element)
            -> bool { return element.second > min_number; })};

    if (found_number != number_frequency.end()) {
      std::cout << found_number->first << "\n";
    } else {
      std::cout << "-1\n";
    }
  }

  return 0;
}