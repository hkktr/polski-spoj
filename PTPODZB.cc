// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

void PrintVector(const std::vector<int>& vector) {
  for (int element : vector) {
    std::cout << element << " ";
  }
}

void PrintSubsets(std::vector<int> a, std::vector<int> b, int k) {
  if (k == 0) {
    PrintVector(b);
    std::cout << "\n";
  } else if (k == a.size()) {
    PrintVector(b);
    PrintVector(a);
    std::cout << "\n";
  } else {
    b.push_back(a.front());
    a.erase(a.begin());

    PrintSubsets(a, b, k - 1);
    b.pop_back();
    PrintSubsets(a, b, k);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a, b;
    a.reserve(n);
    for (int i{1}; i <= n; ++i) {
      a.push_back(i);
    }

    PrintSubsets(a, b, k);
    std::cout << "\n";
  }

  return 0;
}