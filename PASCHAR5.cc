// C++14 (gcc 8.3)
#include <cctype>
#include <iostream>
#include <string>

void Cipher(std::string& text) {
  for (char& character : text) {
    if (std::islower(character)) {
      character -= 13;
      if (character < 'a') character += 'z' - 'a' + 1;
    } else if (std::isupper(character)) {
      character += 13;
      if (character > 'Z') character -= 'Z' - 'A' + 1;
    } else if (std::isdigit(character)) {
      character += 5;
      if (character > '9') character -= '9' - '0' + 1;
    }
  }
}

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    Cipher(line);
    std::cout << line << "\n";
  }

  return 0;
}