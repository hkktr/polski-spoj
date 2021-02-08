// C++14 (gcc 8.3)
#include <iostream>

int main() {
  constexpr int kStackSize{10};
  int stack[kStackSize];
  int stack_size{0};

  char operation;
  while (std::cin >> operation) {
    if (operation == '+') {
      int number;
      std::cin >> number;

      if (stack_size < kStackSize) {
        stack[stack_size] = number;
        ++stack_size;
        std::cout << ":)";
      } else {
        std::cout << ":(";
      }
    } else if (operation == '-') {
      if (stack_size > 0) {
        --stack_size;
        std::cout << stack[stack_size];
      } else {
        std::cout << ":(";
      }
    }
    std::cout << "\n";
  }
}