// C++14 (gcc 8.3)
#include <iostream>

int main() {
  std::cout << "Mundial ";
  std::cout << static_cast<int>('c' - 'a');
  std::cout << static_cast<int>('a' - 'a');
  std::cout << static_cast<int>('b' - 'a');
  std::cout << static_cast<int>('e' - 'a');
  std::cout << "\n";
}