// C++14 (gcc 8.3)
#include <iostream>

bool IsPrime(int n) {
  if (n <= 1) {
    return false;
  }

  for (int i{2}; i <= n; ++i) {
    if (n % i == 0) {
      if (i == n) {
        return true;
      }
      return false;
    }
  }
}

int main() {
  int n;
  std::cin >> n;

  while (--n >= 0) {
    int number;
    std::cin >> number;
    std::cout << (IsPrime(number) ? "TAK" : "NIE") << "\n";
  }

  return 0;
}