// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }

  std::sort(words.begin(), words.end());
  for (auto it{words.begin()}; it != words.end(); ++it) {
    std::cout << *it << "\n";
  }

  return 0;
}