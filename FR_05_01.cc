// C++14 (gcc 8.3)
#include <iostream>

int DayNumber(const std::string& day_string) {
  if (day_string == "Pn") return 0;
  if (day_string == "Wt") return 1;
  if (day_string == "Sr") return 2;
  if (day_string == "Cz") return 3;
  if (day_string == "Pt") return 4;
  if (day_string == "So") return 5;
  if (day_string == "Nd") return 6;
  return -1;
}

std::string DayName(int day_number) {
  switch (day_number) {
    case 0:
      return "Pn";
    case 1:
      return "Wt";
    case 2:
      return "Sr";
    case 3:
      return "Cz";
    case 4:
      return "Pt";
    case 5:
      return "So";
    case 6:
      return "Nd";
    default:
      return "???";
  }
}

int main() {
  int d;
  std::cin >> d;

  std::string day_string;
  int day_move;
  while (--d >= 0) {
    std::cin >> day_string >> day_move;
    std::cout << DayName((DayNumber(day_string) + day_move) % 7) << "\n";
  }

  return 0;
}