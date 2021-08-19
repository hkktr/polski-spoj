// C++ (gcc 8.3)
#include <cmath>
#include <iostream>

void PrintTriangle(int start, int difference, int n) {
  std::cout << start << "\n";

  int last{start};
  while (--difference) {
    last -= difference;
    for (int next{last}, i{difference + 1}; next <= n; next += i, ++i) {
      std::cout << next << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  const int difference{static_cast<int>((-1 + std::sqrt(1 + 8 * n)) / 2)};
  const int term{difference * (difference + 1) / 2};

  if (term == n) {
    PrintTriangle(term - difference + 1, difference, n);
  } else {
    PrintTriangle(term + 1, difference + 1, n);
  }

  return 0;
}