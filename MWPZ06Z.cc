// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::string c;
  while (--t >= 0) {
    int l;
    std::cin >> l >> c;

    int n;
    if (c.size() > 2) {
      n = std::stoi(c.substr(c.size() - 2));
    } else {
      n = std::stoi(c);
    }

    std::cout << (n % l == 0 ? "TAK" : "NIE") << "\n";
  }

  return 0;
}