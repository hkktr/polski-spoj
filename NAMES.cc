// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string Uppercase(const std::string& text) {
  std::string result;
  result.reserve(text.size());

  for (const char& character : text) {
    if (character >= 'a' && character <= 'z') {
      result.push_back(character - ('a' - 'A'));
    } else {
      result.push_back(character);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::map<std::string, int> names_frequency;

  std::string trash, name;
  while (std::cin >> trash >> trash >> name) {
    ++names_frequency[Uppercase(name)];
  }

  std::vector<std::pair<std::string, int>> result;
  result.reserve(names_frequency.size());
  for (auto it{names_frequency.begin()}; it != names_frequency.end(); ++it) {
    result.push_back(std::make_pair(it->first, it->second));
  }

  std::sort(result.begin(), result.end(),
            [](const std::pair<std::string, int>& lhs,
               const std::pair<std::string, int>& rhs) -> bool {
              if (lhs.second != rhs.second) return lhs.second > rhs.second;
              return lhs.first < rhs.first;
            });

  for (const std::pair<std::string, int>& item : result) {
    std::cout << item.first << " " << item.second << "\n";
  }

  return 0;
}