// C++ (gcc 8.3)
#include <bitset>
#include <iomanip>
#include <iostream>
#include <string>

constexpr bool IsLeapYear(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

constexpr int DaysInMonth(int month, int year) {
  switch (month) {
    case 2:
      return (IsLeapYear(year) ? 29 : 28);
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
  }
}

constexpr bool IsValidDate(int year, int month, int day) {
  return month >= 1 && month <= 12 && day >= 1 &&
         day <= DaysInMonth(month, year);
}

void ConvertDOSFATT(const std::string& date) {
  const int year{
      1980 + static_cast<int>(std::bitset<7>(date.substr(0, 7)).to_ulong())};
  const int month{
      static_cast<int>(std::bitset<4>(date.substr(7, 11)).to_ulong())};
  const int day{
      static_cast<int>(std::bitset<5>(date.substr(11, 16)).to_ulong())};

  if (IsValidDate(year, month, day)) {
    std::cout << year << "-";
    std::cout << std::setw(2) << std::setfill('0') << month << "-";
    std::cout << std::setw(2) << std::setfill('0') << day << "\n";
  } else {
    std::cout << "ERROR\n";
  }
}

void ConvertISO8601(const std::string& date) {
  if (date[4] != '-' || date[7] != '-') {
    std::cout << "ERROR\n";
    return;
  }

  const int year{std::stoi(date.substr(0, 4))};
  const int month{std::stoi(date.substr(5, 7))};
  const int day{std::stoi(date.substr(8, 10))};

  if (year >= 1980 && year <= 2107 && IsValidDate(year, month, day)) {
    const int year_difference{year - 1980};
    std::cout << std::bitset<7>(year_difference).to_string()
              << std::bitset<4>(month).to_string()
              << std::bitset<5>(day).to_string() << "\n";
  } else {
    std::cout << "ERROR\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string date;
  date.reserve(16);
  std::cin >> date;

  if (date.size() == 16) {
    ConvertDOSFATT(date);
  } else if (date.size() == 10) {
    ConvertISO8601(date);
  } else {
    std::cout << "ERROR\n";
  }

  return 0;
}