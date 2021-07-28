// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

std::vector<int> LPSArray(const std::string& pattern) {
  const int m{static_cast<int>(pattern.size())};

  std::vector<int> lps(m);
  lps[0] = 0;

  int length{0};
  int i{1};
  while (i < m) {
    if (pattern[i] == pattern[length]) {
      lps[i] = ++length;
      ++i;
    } else {
      if (length != 0) {
        length = lps[length - 1];
      } else {
        lps[i] = 0;
        ++i;
      }
    }
  }

  return lps;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::string pattern;
  std::vector<int> lps_array;
  while (--t >= 0) {
    std::cin >> pattern;
    lps_array = LPSArray(pattern);

    for (int value : lps_array) {
      std::cout << value << " ";
    }
    std::cout << "\n";
  }

  return 0;
}