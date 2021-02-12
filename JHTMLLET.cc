// C++14 (gcc 8.3)
#include <iostream>
#include <string>
#include <vector>

char ToUpper(char character) {
  if (character >= 'a' && character <= 'z') {
    return 'A' + (character - 'a');
  }
  return character;
}

int main() {
  std::vector<std::string> lines;
  std::string input_line;
  while (std::getline(std::cin, input_line)) {
    bool edit{false};
    for (char& character : input_line) {
      if (character == '<') {
        edit = true;
      } else if (character == '>') {
        edit = false;
      } else if (edit) {
        character = ToUpper(character);
      }
    }

    lines.push_back(input_line);
  }

  std::cout << "\n";
  for (const std::string& line : lines) {
    std::cout << line << "\n";
  }

  return 0;
}