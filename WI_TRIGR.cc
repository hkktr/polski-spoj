// C++ (gcc 8.3)
#include <iostream>
#include <string>

void ReplaceAll(std::string& source, const std::string& from,
                const std::string& to) {
  std::string result;
  result.reserve(source.size());

  std::size_t last_position{0};
  std::size_t find_position;
  while ((find_position = source.find(from, last_position)) != source.npos) {
    result.append(source, last_position, find_position - last_position);
    result += to;
    last_position = find_position + from.size();
  }

  result += source.substr(last_position);
  source.swap(result);
}

int main() {
  const std::string trigraphs[9]{"??=", "??/", "??'", "??(", "??)",
                                 "??!", "??<", "??>", "??-"};
  const std::string trigraphs_equivalents[9]{"#", "\\", "^", "[", "]",
                                             "|", "{",  "}", "~"};

  std::string line;
  while (std::getline(std::cin, line)) {
    if (line.find("??") != line.npos) {
      for (int i{0}; i < 9; ++i) {
        ReplaceAll(line, trigraphs[i], trigraphs_equivalents[i]);
      }
    }
    std::cout << line << "\n";
  }

  return 0;
}