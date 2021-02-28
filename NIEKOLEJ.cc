// C++14 (gcc 8.3)
#include <iostream>

void PrintNotNext(int n) {
  int even_start{n}, odd_start{n};
  if (n % 2 == 0) {
    --odd_start;
  } else {
    --even_start;
  }

  for (int i{even_start}; i >= 0; i -= 2) {
    std::cout << i << " ";
  }
  for (int i{odd_start}; i >= 0; i -= 2) {
    std::cout << i << " ";
  }
}

int main() {
  int n;
  std::cin >> n;

  if (n <= 2 && n != 0) {
    std::cout << "NIE";
  } else {
    PrintNotNext(n);
  }

  return 0;
}