// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int CharToInt(char& character) {
  if (character >= '0' && character <= '9') return character - '0';
  return -1;
}

int main() {
  std::string number;
  while (true) {
    std::cin >> number;
    if (number == "0") break;

    if (CharToInt(number[number.size() - 1]) % 5 == 0) {
      int mod3{0};
      for (char digit : number) {
        mod3 += CharToInt(digit);
        mod3 %= 3;
      }

      if (mod3 == 0) {
        std::cout << "TAK\n";
      } else {
        std::cout << "NIE\n";
      }
    } else {
      std::cout << "NIE\n";
    }
  }

  return 0;
}