// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string encrypted_password;
  encrypted_password.reserve(20);

  std::string password;
  password.resize(10);
  while (std::getline(std::cin, encrypted_password)) {
    for (int i{0}; i < 10; ++i) {
      password[i] =
          static_cast<char>(encrypted_password[2 * i] - 'A' +
                            (encrypted_password[2 * i + 1] - 'A') * 16);
    }
    std::cout << password << "\n";
  }

  return 0;
}