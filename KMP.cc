// C++14 (gcc 8.3)
#include <iostream>
#include <string>
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

void KMPSearch(const std::string& pattern, const std::string& text) {
  const int m{static_cast<int>(pattern.size())};
  const int n{static_cast<int>(text.size())};

  const std::vector<int> lps{LPSArray(pattern)};

  int i{0}, j{0};
  while (i < n) {
    if (pattern[j] == text[i]) {
      ++j;
      ++i;
    }

    if (j == m) {
      std::cout << i - j << "\n";
      j = lps[j - 1];
    } else if (i < n && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        ++i;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::string pattern, text;
  while (--t >= 0) {
    int n;
    std::cin >> n;
    pattern.reserve(n);

    std::cin >> pattern >> text;
    KMPSearch(pattern, text);
  }

  return 0;
}