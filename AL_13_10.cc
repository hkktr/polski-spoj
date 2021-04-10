// C++14 (gcc 8.3)
#include <iostream>

bool IsSubsequence(const std::string& a, const std::string& b) {
  if (a.size() > b.size()) return false;

  std::size_t j{0};
  for (std::size_t i{0}; i < b.size() && j < a.size(); ++i) {
    if (a[j] == b[i]) ++j;
  }

  return j == a.size();
}

int main() {
  int t;
  std::cin >> t;

  std::string a, b;
  while (--t >= 0) {
    std::cin >> a >> b;
    std::cout << (IsSubsequence(b, a) ? "Tak" : "Nie") << "\n";
  }

  return 0;
}