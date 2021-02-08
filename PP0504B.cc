// C++14 (gcc 8.3)
#include <iostream>

char* StringMerge(char* a, char* b) {
  int length{0};
  while (a[length] != '\0' && b[length] != '\0') {
    ++length;
  }

  const int merged_size{2 * length + 1};
  char* merged_string{new char[merged_size]};
  for (int i{0}; i < length; ++i) {
    merged_string[2 * i] = a[i];
    merged_string[2 * i + 1] = b[i];
  }
  merged_string[merged_size - 1] = '\0';

  return merged_string;
}

int main() {
  int t;
  std::cin >> t;

  constexpr int kMaxSize{1001};
  char a[kMaxSize], b[kMaxSize], *merged;
  while (--t >= 0) {
    std::cin >> a >> b;

    merged = StringMerge(a, b);
    std::cout << merged << "\n";
    delete[] merged;
  }

  return 0;
}