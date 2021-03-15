// C++14 (gcc 8.3)
#include <iostream>
#include <set>

int main() {
  std::multiset<int> ascii_count;
  char character;
  while (std::cin.get(character)) {
    ascii_count.insert(static_cast<unsigned char>(character));
  }

  for (auto it{ascii_count.begin()}; it != ascii_count.end();) {
    const std::size_t count{ascii_count.count(*it)};
    std::cout << *it << " " << count << "\n";
    std::advance(it, count);
  }

  return 0;
}