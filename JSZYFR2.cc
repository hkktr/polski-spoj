// C++14 (gcc 8.3)
#include <array>
#include <iostream>
#include <string>
#include <vector>

void Decipher(const std::vector<int>& ciphered) {
  constexpr std::array<int, 5> kKeys{127, 131, 137, 139, 149};

  int good_keys{0};
  int good_key{0};
  for (int key : kKeys) {
    bool good{true};
    for (int code : ciphered) {
      const char deciphered_character{static_cast<char>(code % key)};
      if (deciphered_character < 'A' || deciphered_character > 'Z') {
        good = false;
        break;
      }
    }

    if (good) {
      ++good_keys;
      good_key = key;
      if (good_keys > 1) break;
    }
  }

  if (good_keys == 1) {
    std::cout << good_key << " ";
    for (int code : ciphered) {
      std::cout << static_cast<char>(code % good_key);
    }
    std::cout << "\n";
  } else {
    std::cout << "NIECZYTELNE\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int s;
    std::cin >> s;

    std::vector<int> ciphered(s);
    for (int& code : ciphered) {
      std::cin >> code;
    }

    Decipher(ciphered);
  }

  return 0;
}