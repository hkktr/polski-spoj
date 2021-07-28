// C++ (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> DivideBy2(const std::vector<int>& number) {
  std::vector<int> result;
  result.reserve(number.size());

  std::size_t index{0};
  int temp{number[index]};
  while (temp < 2 && number.size() > index + 1) {
    temp = temp * 10 + number[++index];
  }

  result.push_back(temp >> 1);
  while (number.size() > ++index) {
    temp = (temp & 1) * 10 + number[index];
    result.push_back(temp >> 1);
  }

  return result;
}

std::vector<char> DecimalToBinary(std::vector<int>& decimal, int bits) {
  std::vector<char> binary;
  binary.reserve(bits);

  while (decimal.size() > 1 || decimal.front() != 0) {
    binary.push_back(decimal.back() & 1);
    decimal = DivideBy2(decimal);
  }

  if (binary.empty()) return {0};
  std::reverse(binary.begin(), binary.end());
  return binary;
}

std::vector<int> GetNumber() {
  std::string string_number;
  std::cin >> string_number;

  std::vector<int> number;
  number.reserve(string_number.size());

  for (char digit : string_number) {
    number.push_back(digit - '0');
  }
  return number;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> m{GetNumber()};
  const std::vector<char> binary{DecimalToBinary(m, n)};

  std::cout << static_cast<bool>(binary[0]);
  for (std::size_t i{0}; i < binary.size() - 1; ++i) {
    std::cout << (binary[i] ^ binary[i + 1]);
  }
  std::cout << "\n";

  return 0;
}