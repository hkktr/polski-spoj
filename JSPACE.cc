// C++14 (gcc 8.3)
#include <iostream>
#include <string>

char ToUpper(char character) {
  if (character >= 'a' && character <= 'z') {
    return 'A' + (character - 'a');
  }
  return character;
}

int main() {
  std::string input_line;
  while (std::getline(std::cin, input_line)) {
    std::string result;
    for (std::size_t i{0}; i < input_line.size(); ++i) {
      if (input_line[i] == ' ' && i < input_line.size() - 1) {
        input_line[i + 1] = ToUpper(input_line[i + 1]);
      } else {
        result += input_line[i];
      }
    }

    std::cout << result << "\n";
  }

  return 0;
}