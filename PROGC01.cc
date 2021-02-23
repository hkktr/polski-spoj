// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::string temp;
  int lines_counter{0};
  while (std::getline(std::cin, temp)) {
    ++lines_counter;
  }

  std::cout << lines_counter;

  return 0;
}