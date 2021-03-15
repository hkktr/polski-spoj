// C++14 (gcc 8.3)
#include <array>
#include <cmath>
#include <iostream>
#include <string>

int CharToInt(char character) {
  if (character >= '0' && character <= '9') return character - '0';
  return -1;
}

std::string StringNumber(std::string string_number) {
  const std::array<std::string, 9> hundreds{
      "sto",      "dwiescie",  "trzysta",  "czterysta",  "piecset",
      "szescset", "siedemset", "osiemset", "dziewiecset"};
  const std::array<std::string, 9> tens{
      "dziesiec",       "dwadziescia",   "trzydziesci",
      "czterdziesci",   "piecdziesiat",  "szescdziesiat",
      "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
  const std::array<std::string, 20> units_and_teens{
      "jeden",        "dwa",         "trzy",          "cztery",
      "piec",         "szesc",       "siedem",        "osiem",
      "dziewiec",     "dziesiec",    "jedenascie",    "dwanascie",
      "trzynascie",   "czternascie", "pietnascie",    "szesnascie",
      "siedemnascie", "osiemnascie", "dziewietnascie"};

  string_number.erase(0, string_number.find_first_not_of('0'));
  if (string_number.empty()) return "";

  std::string result;
  if (string_number.size() == 3) {
    result += hundreds[CharToInt(string_number[0] - 1)];
    if (string_number[1] == '0' && string_number[2] == '0') return result;
    result += " ";
    string_number[0] = ' ';
  }

  const int value{std::stoi(string_number)};
  if (value < 20) {
    result += units_and_teens[value - 1];
  } else {
    result += tens[value / 10 - 1];
    if (value % 10 != 0) {
      result += " " + units_and_teens[value % 10 - 1];
    }
  }

  return result;
}

void PrintStringRepresentation(long long number) {
  const std::array<std::string, 4> shortcuts{"tys.", "mln.", "mld.", "bln."};
  const std::string string_number{std::to_string(number)};
  const int fragments{static_cast<int>(std::ceil(string_number.size() / 3.0))};

  if (fragments == 1) {
    std::cout << StringNumber(string_number) << "\n";
  } else {
    std::size_t start;
    if (string_number.size() % 3 != 0) {
      start = string_number.size() % 3;
    } else {
      start = 3;
    }

    std::cout << StringNumber(string_number.substr(0, start));
    std::cout << " " << shortcuts[fragments - 2] << " ";

    for (int i{1}; i < fragments; ++i) {
      const std::string fragment{string_number.substr(start + (i - 1) * 3, 3)};
      const std::string string_fragment{StringNumber(fragment)};

      std::cout << string_fragment;
      if (!string_fragment.empty() && i != fragments - 1) {
        std::cout << " " << shortcuts[fragments - i - 2] << " ";
      }
    }
    std::cout << "\n";
  }
}

int main() {
  int t;
  std::cin >> t;

  long long number;
  while (--t >= 0) {
    std::cin >> number;
    PrintStringRepresentation(number);
  }

  return 0;
}