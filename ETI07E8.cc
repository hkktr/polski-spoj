// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int LetterDigit(char letter) {
  if (letter == 'a' || letter == 'b' || letter == 'c') return 2;
  if (letter == 'd' || letter == 'e' || letter == 'f') return 3;
  if (letter == 'g' || letter == 'h' || letter == 'i') return 4;
  if (letter == 'j' || letter == 'k' || letter == 'l') return 5;
  if (letter == 'm' || letter == 'n' || letter == 'o') return 6;
  if (letter == 'p' || letter == 'q' || letter == 'r' || letter == 's')
    return 7;
  if (letter == 't' || letter == 'u' || letter == 'v') return 8;
  if (letter == 'w' || letter == 'x' || letter == 'y' || letter == 'z')
    return 9;
}

long long WordNumber(const std::string& word) {
  long long result{0};
  for (char letter : word) {
    result *= 10;
    result += LetterDigit(letter);
  }
  return result;
}

int main() {
  int n, k;
  std::cin >> n >> k;

  std::unordered_map<long long, std::vector<std::string>> dictionary;
  std::string word;
  while (--n >= 0) {
    std::cin >> word;
    dictionary[WordNumber(word)].push_back(word);
  }

  while (--k >= 0) {
    long long number;
    std::cin >> number;

    const auto found{dictionary.find(number)};
    if (found != dictionary.end()) {
      std::sort(found->second.begin(), found->second.end());
      for (auto it{found->second.begin()}; it != found->second.end(); ++it) {
        std::cout << *it << " ";
      }
      std::cout << "\n";
    } else {
      std::cout << "BRAK\n";
    }
  }

  return 0;
}