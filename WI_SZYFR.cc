// C++ (gcc 8.3)
#include <iostream>
#include <string>

std::string& Cipher(std::string& text, const std::string& key) {
  if (key.empty()) return text;

  for (std::size_t i{0}; i < text.size(); ++i) {
    const int key_value{key[i % key.size()] - '0'};
    text[i] += static_cast<char>(key_value);
    if (text[i] > 'Z') text[i] -= ('Z' - 'A' + 1);
  }

  return text;
}

std::string& Decipher(std::string& text, const std::string& key) {
  if (key.empty()) return text;

  for (std::size_t i{0}; i < text.size(); ++i) {
    const int key_value{key[i % key.size()] - '0'};
    text[i] -= static_cast<char>(key_value);
    if (text[i] < 'A') text[i] += ('Z' - 'A' + 1);
  }

  return text;
}

int main() {
  std::string command, key, text;
  std::cin >> command >> key >> text;

  key.erase(0, key.find_first_not_of('0'));

  if (command == "SZYFRUJ") {
    std::cout << Cipher(text, key) << "\n";
  } else if (command == "DESZYFRUJ") {
    std::cout << Decipher(text, key) << "\n";
  }

  return 0;
}