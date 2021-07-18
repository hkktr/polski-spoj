// C++14 (gcc 8.3)
#include <iostream>
#include <map>
#include <vector>

struct Product {
  int index;
  unsigned long long quantity;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::map<int, int> indexes;
  std::vector<Product> report;

  while (--n >= 0) {
    int a;
    unsigned long long b;
    std::cin >> a >> b;

    const auto index{indexes.find(a)};
    if (index == indexes.end()) {
      report.push_back(Product{a, b});
      indexes.insert(std::make_pair(a, report.size() - 1));
    } else {
      report[index->second].quantity += b;
    }
  }

  std::cout << report.size() << "\n";
  for (const Product& product : report) {
    std::cout << product.index << " " << product.quantity << "\n";
  }

  return 0;
}