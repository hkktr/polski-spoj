// C++14 (gcc 8.3)
#include <cctype>
#include <iostream>
#include <string>

bool IsStrongPassword(const std::string& password) {
  if (password.size() < 8) return false;

  unsigned password_strength_flags{0};
  for (char character : password) {
    if (std::islower(character)) {
      password_strength_flags |= 0b1000;
    } else if (std::isupper(character)) {
      password_strength_flags |= 0b0100;
    } else if (std::isdigit(character)) {
      password_strength_flags |= 0b0010;
    } else {
      password_strength_flags |= 0b0001;
    }

    if (password_strength_flags == 0b1111) return true;
  }

  return password_strength_flags == 0b1111;
}

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

  std::string password;
  while (--n >= 0) {
    std::getline(std::cin, password);
    if (IsStrongPassword(password)) {
      std::cout << password << "\n";
    }
  }

  return 0;
}