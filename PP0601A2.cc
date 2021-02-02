// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int last_number{42};
  int number;
  int counter{0};
  while (true) {
    std::cin >> number;
    std::cout << number << "\n";

    if (last_number != 42 && number == 42) ++counter;
    if (counter == 3) break;
    last_number = number;
  }

  return 0;
}