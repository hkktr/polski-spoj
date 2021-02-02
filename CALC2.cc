// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int memory[10]{};

  char operation;
  int a, b;
  while (std::cin >> operation >> a >> b) {
    switch (operation) {
      case 'z':
        memory[a] = b;
        break;
      case '+':
        std::cout << memory[a] + memory[b] << "\n";
        break;
      case '-':
        std::cout << memory[a] - memory[b] << "\n";
        break;
      case '*':
        std::cout << memory[a] * memory[b] << "\n";
        break;
      case '/':
        std::cout << memory[a] / memory[b] << "\n";
        break;
      case '%':
        std::cout << memory[a] % memory[b] << "\n";
        break;
    }
  }

  return 0;
}