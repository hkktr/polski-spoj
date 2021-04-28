// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> lyrics;
  std::string word;
  do {
    std::cin >> word;
    lyrics.push_back(word);
  } while (std::cin.get() != '\n');

  std::vector<std::string> skipped_words;
  std::vector<std::string>::iterator last{lyrics.begin()};
  do {
    std::cin >> word;

    const auto found{std::find(last, lyrics.end(), word)};
    for (last; last != found; ++last) {
      skipped_words.push_back(*last);
    }
  } while (++last != lyrics.end() && std::cin.get() != '\n');

  for (last; last != lyrics.end(); ++last) {
    skipped_words.push_back(*last);
  }
  std::sort(skipped_words.begin(), skipped_words.end());

  std::cout << skipped_words.size() << "\n";
  for (const std::string& skipped_word : skipped_words) {
    std::cout << skipped_word << "\n";
  }

  return 0;
}