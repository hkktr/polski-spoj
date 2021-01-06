// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int d;
  std::cin >> d;

  while (--d >= 0) {
    int n;
    std::cin >> n;

    switch (n) {
      case 0:
      case 1:
        std::cout << "0 1";
        break;
      case 2:
        std::cout << "0 2";
        break;
      case 3:
        std::cout << "0 6";
        break;
      case 4:
        std::cout << "2 4";
        break;
      case 5:
      case 6:
      case 8:
        std::cout << "2 0";
        break;
      case 7:
        std::cout << "4 0";
        break;
      case 9:
        std::cout << "8 0";
        break;
      default:
        std::cout << "0 0";
        break;
    }
    std::cout << "\n";
  }

  return 0;
}