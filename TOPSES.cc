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

bool AreRotations(const std::string& a, const std::string& b) {
  const std::string text{a + a};

  const int m{static_cast<int>(b.size())};
  const int n{static_cast<int>(text.size())};

  const std::vector<int> lps{LPSArray(b)};

  int i{0}, j{0};
  while (i < n) {
    if (b[j] == text[i]) {
      ++j;
      ++i;
    }

    if (j == m) return true;
    if (i < n && b[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        ++i;
      }
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::string a, b;
  while (--t >= 0) {
    std::cin >> a;
    b.reserve(a.size());
    std::cin >> b;

    std::cout << (AreRotations(a, b) ? "yes" : "no") << "\n";
  }

  return 0;
}