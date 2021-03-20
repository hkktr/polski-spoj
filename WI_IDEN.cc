// C++ (gcc 8.3)
#include <cctype>
#include <iostream>
#include <string>

bool IsVowel(char character) {
  switch (std::tolower(character)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
      return true;

    default:
      return false;
  }
}

void ShortenVariableName(std::string& name, std::size_t n) {
  if (name.size() <= n) return;

  for (auto it{name.begin()}; it != name.end(); ++it) {
    if (!std::isalnum(*it) && *it != '$') {
      name.erase(it);
      if (it != name.begin()) --it;

      if (name.size() <= n) return;
    }
  }

  for (auto it{name.rbegin()}; it != name.rend(); ++it) {
    if (std::isdigit(*it)) {
      name.erase(std::next(it).base());

      if (name.size() <= n) return;
    }
  }

  bool first_vowel{true};
  for (auto it{name.begin()}; it != name.end(); ++it) {
    if (IsVowel(*it)) {
      if (first_vowel) {
        first_vowel = false;
      } else {
        name.erase(it);
        if (it != name.begin()) --it;

        if (name.size() <= n) return;
      }
    }
  }

  for (auto it{name.rbegin() + 1}; it != name.rend(); ++it) {
    name.erase(std::next(it).base());

    if (name.size() <= n) return;
  }
}

int main() {
  std::size_t n;
  std::cin >> n;

  std::string variable_name;
  std::cin >> variable_name;

  ShortenVariableName(variable_name, n);
  std::cout << variable_name;

  return 0;
}