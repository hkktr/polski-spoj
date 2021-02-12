// C++14 (gcc 8.3)
#include <iostream>

 int main() {
  int target_number, n;
  while (std::cin >> target_number >> n) {
    int counter{0};
    while (--n >= 0) {
      int number;
      std::cin >> number;

      if (number == target_number) ++counter;
    }

    std::cout << counter << "\n";
  }

  return 0;
}