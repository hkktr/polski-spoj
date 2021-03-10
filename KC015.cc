// C++14 (gcc 8.3)
#include <iostream>

int main() {
  std::string a, operation, b;
  while (std::cin >> a >> operation >> b) {
    if (operation == "==") {
      std::cout << (a == b);
    } else if (operation == "!=") {
      std::cout << (a != b);
    } else if (operation == "<=") {
      std::cout << (a.size() < b.size() || (a.size() == b.size() && a < b) ||
                    a == b);
    } else if (operation == ">=") {
      std::cout << (a.size() > b.size() || (a.size() == b.size() && a > b) ||
                    a == b);
    }
    std::cout << "\n";
  }

  return 0;
}