// C++14 (gcc 8.3)
#include <array>
#include <iostream>
#include <map>
#include <string>

int RomanToDecimal(const std::string& roman) {
  const std::map<char, int> kRomanValues{{'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000}};

  int result{0};
  for (std::size_t i{0}; i < roman.size() - 1; ++i) {
    if (kRomanValues.at(roman[i + 1]) <= kRomanValues.at(roman[i])) {
      result += kRomanValues.at(roman[i]);
    } else {
      result -= kRomanValues.at(roman[i]);
    }
  }
  result += kRomanValues.at(roman[roman.size() - 1]);

  return result;
}

std::string DecimalToRoman(int decimal) {
  constexpr std::array<int, 13> kRomanValues{1000, 900, 500, 400, 100, 90, 50,
                                             40,   10,  9,   5,   4,   1};
  const std::array<std::string, 13> kRomanSymbols{
      "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
  };

  std::string result;
  int i{0};
  while (decimal > 0) {
    while (decimal >= kRomanValues[i]) {
      result.append(kRomanSymbols[i]);
      decimal -= kRomanValues[i];
    }
    ++i;
  }

  return result;
}

std::string RomanSum(const std::string& a, const std::string& b) {
  return DecimalToRoman(RomanToDecimal(a) + RomanToDecimal(b));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string a, b;
  while (std::cin >> a >> b) {
    std::cout << RomanSum(a, b) << "\n";
  }

  return 0;
}