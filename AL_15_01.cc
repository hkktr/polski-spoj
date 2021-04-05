// C++14 (gcc 8.3)
#include <iostream>
#include <string>

int main() {
  std::string wrong_answers;
  std::cin >> wrong_answers;

  std::string a, b;
  a.reserve(wrong_answers.size());
  b.reserve(wrong_answers.size());
  std::cin >> a >> b;

  int result{0};
  for (std::size_t i{0}; i < wrong_answers.size(); ++i) {
    if (a[i] != wrong_answers[i]) ++result;
    if (b[i] != wrong_answers[i] && a[i] == b[i]) ++result;
    if (a[i] == wrong_answers[i] && a[i] != b[i]) ++result;
  }

  std::cout << result;

  return 0;
}