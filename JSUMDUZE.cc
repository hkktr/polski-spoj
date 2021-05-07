// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>

std::string StringSum(std::string& a, std::string& b) {
  if (a.size() > b.size()) std::swap(a, b);

  const int n1{static_cast<int>(a.size())};
  const int n2{static_cast<int>(b.size())};
  const int difference{n2 - n1};

  std::string result;
  int carry{0};
  for (int i{n1 - 1}; i >= 0; --i) {
    const int sum{(a[i] - '0') + (b[i + difference] - '0') + carry};
    result.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  for (int i{n2 - n1 - 1}; i >= 0; --i) {
    const int sum{(b[i] - '0') + carry};
    result.push_back(sum % 10 + '0');
    carry = sum / 10;
  }

  if (carry) result.push_back(static_cast<char>(carry) + '0');
  std::reverse(result.begin(), result.end());

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::string a, b;
  while (--t >= 0) {
    std::cin >> a >> b;
    std::cout << StringSum(a, b) << "\n";
  }

  return 0;
}