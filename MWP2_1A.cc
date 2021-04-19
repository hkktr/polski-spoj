// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

int main() {
  int d;
  std::cin >> d;

  std::vector<int> sequence;
  while (--d >= 0) {
    int k;
    std::cin >> k;

    sequence.resize(k);
    for (int& number : sequence) {
      std::cin >> number;
    }

    int best{0};
    int result{0};
    for (int i{0}; i < k; ++i) {
      int count{0};
      for (int j{0}; j < k; ++j) {
        count += sequence[(i + j) % k] == j + 1;
      }

      if (count > best) {
        best = count;
        result = i;
      }
    }

    for (int i{0}; i < k; ++i) {
      std::cout << sequence[(i + result) % k] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}