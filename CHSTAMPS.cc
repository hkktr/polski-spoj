// C++14 (gcc 8.3)
#include <iostream>
#include <list>
#include <string>

void Increment(std::string::reverse_iterator number_rit, std::string& number,
               int& fives, int fives_target,
               std::list<bool>::reverse_iterator changed_rit,
               std::list<bool>& changed) {
  if (*number_rit == '9' || (*number_rit >= '5' && *changed_rit)) {
    if (number_rit == number.rend() - 1) {
      number.insert(number.begin(), '0');
      changed.insert(changed.begin(), true);
      number_rit = number.rend() - 2;
    }

    Increment(++number_rit, number, fives, fives_target, ++changed_rit,
              changed);
  } else if (!*changed_rit) {
    ++*number_rit;
    *changed_rit = true;

    if (*number_rit == '5') {
      ++fives;
    } else if (*number_rit == '6') {
      --fives;
    }

    for (auto rit{number.rbegin()}; rit != number_rit; ++rit) {
      if (*rit != '5') {
        ++fives;
      }
      *rit = '5';
    }

    for (auto it{number_rit.base()}; it != number.end() && fives > fives_target;
         ++it) {
      --fives;
      *it = '0';
    }
  } else if (*number_rit < '5') {
    *number_rit = '5';
    ++fives;
  }
}

std::string& NextNumber(std::string& number, int fives_target) {
  int fives{0};
  for (char character : number) {
    if (character == '5') ++fives;
  }

  std::list<bool> changed(number.size() + 1, false);
  std::string::reverse_iterator number_rit;
  std::list<bool>::reverse_iterator changed_rit;

  do {
    number_rit = number.rbegin();
    changed_rit = changed.rbegin();
    Increment(number_rit, number, fives, fives_target, changed_rit, changed);
  } while (fives < fives_target);

  return number;
}

int main() {
  std::string n;
  int k;

  std::cin >> n >> k;
  std::cout << NextNumber(n, k) << "\n";

  return 0;
}