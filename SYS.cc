// C++14 (gcc 8.3)
#include <iostream>
#include <string>

std::string DecimalToHex(int decimal) {
  std::string hex;
  while (decimal > 0) {
    const int remainder{decimal % 16};
    decimal /= 16;
    if (remainder < 10) {
      hex.insert(0, std::to_string(remainder));
    } else {
      hex.insert(0, 1, static_cast<char>('A' + (remainder - 10)));
    }
  }
  return hex;
}

std::string DecimalToUndecimal(int decimal) {
  std::string undecimal;
  while (decimal > 0) {
    const int remainder{decimal % 11};
    decimal /= 11;
    if (remainder < 10) {
      undecimal.insert(0, std::to_string(remainder));
    } else {
      undecimal.insert(0, 1, 'A');
    }
  }
  return undecimal;
}

int main() {
  int t;
  std::cin >> t;

  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::cout << DecimalToHex(n) << " " << DecimalToUndecimal(n) << "\n";
  }

  return 0;
}