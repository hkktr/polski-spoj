// C++14 (gcc 8.3)
#include <iostream>

int main() {
  char operator_type;
  while (std::cin >> operator_type) {
    int a, b;
    std::cin >> a >> b;

    switch (operator_type) {
      case '+':
        std::cout << a + b;
        break;
      case '-':
        std::cout << a - b;
        break;
      case '*':
        std::cout << a * b;
        break;
      case '/':
        std::cout << a / b;
        break;
      case '%':
        std::cout << a % b;
        break;
    }
    std::cout << "\n";
  }

  return 0;
}