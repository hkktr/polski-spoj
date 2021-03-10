// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

  while (--n >= 0) {
    int result{0};
    char operation{'\0'};

    char input;
    while ((input = static_cast<char>(getchar())) != '\n') {
      if (input == '+' || input == '-') {
        operation = input;
      } else {
        const int value{static_cast<int>(input - '0')};
        if (operation == '+') {
          result += value;
        } else if (operation == '-') {
          result -= value;
        } else {
          result = value;
        }
      }
    }

    std::cout << result << "\n";
  }

  return 0;
}