// C++14 (gcc 8.3)
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int animals_bits{0};
  int animal_id;
  while (std::cin >> animal_id) {
    animals_bits ^= animal_id;
  }

  std::cout << animals_bits << "\n";

  return 0;
}