// C++14 (gcc 8.3)
#include <cctype>
#include <iostream>
#include <string>

bool IsValidName(const std::string& name) {
  if (!std::isupper(name[0])) return false;
  for (auto it{name.begin() + 1}; it != name.end() - 1; ++it) {
    if (!std::islower(*it)) return false;
  }
  return true;
}

bool IsValidLastName(const std::string& last_name) {
  if (!std::isupper(last_name[0])) return false;
  if (last_name.size() == 2) return false;
  for (auto it{last_name.begin() + 1}; it != last_name.end() - 1; ++it) {
    if (!std::islower(*it)) return false;
  }
  return true;
}

bool IsNumber(const std::string& string) {
  for (char character : string) {
    if (!std::isdigit(character)) return false;
  }
  return true;
}

bool IsValidDate(const std::string& date) {
  if (!IsNumber(date.substr(0, 4))) return false;
  if (!IsNumber(date.substr(5, 2))) return false;
  if (!IsNumber(date.substr(8, 2))) return false;

  const int year{std::stoi(date.substr(0, 4))};
  if (!(year >= 1900 && year <= 2000)) return false;
  const int month{std::stoi(date.substr(5, 2))};
  if (!(month >= 1 && month <= 12)) return false;
  const int day{std::stoi(date.substr(8, 2))};
  if (!(day >= 1 && day <= 31)) return false;

  return true;
}

int main() {
  std::string temp, name, last_name, birth_date;
  while (std::cin >> temp >> name >> temp >> last_name >> temp >> temp >>
         birth_date) {
    if (!IsValidName(name)) {
      std::cout << "0\n";
    } else if (!IsValidName(last_name)) {
      std::cout << "1\n";
    } else if (!IsValidDate(birth_date)) {
      std::cout << "2\n";
    } else {
      std::cout << "3\n";
    }
  }

  return 0;
}