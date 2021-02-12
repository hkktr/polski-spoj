// C++14 (gcc 8.3)
#include <iostream>
#include <set>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

  std::multiset<char> letters;
  std::string text;
  while (--n >= 0) {
    std::getline(std::cin, text);

    for (auto it{text.begin()}; it != text.end(); ++it) {
      letters.insert(*it);
    }
  }

  for (char letter{'a'}; letter <= 'z'; ++letter) {
    const unsigned letter_quantity{letters.count(letter)};
    if (letter_quantity > 0) {
      std::cout << letter << " " << letter_quantity << "\n";
    }
  }
  for (char letter{'A'}; letter <= 'Z'; ++letter) {
    const unsigned letter_quantity{letters.count(letter)};
    if (letter_quantity > 0) {
      std::cout << letter << " " << letter_quantity << "\n";
    }
  }

  return 0;
}