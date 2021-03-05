// C++ (gcc 8.3)
#include <iostream>

void PrintFloat(float value) {
  for (int i{sizeof(float) - 1}; i >= 0; --i) {
    std::cout << std::hex
              << static_cast<const int>(
                     (reinterpret_cast<const unsigned char*>(&value))[i])
              << " ";
  }
  std::cout << "\n";
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    float x;
    std::cin >> x;

    PrintFloat(x);
  }

  return 0;
}