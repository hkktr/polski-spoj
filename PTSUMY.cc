// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

void PrintSequences(std::vector<int>& sequence, int min, int left) {
  if (left == 0) {
    for (int element : sequence) {
      std::cout << element << " ";
    }
    std::cout << "\n";
  } else {
    for (int i{min}; left - i >= 0; ++i) {
      sequence.push_back(i);
      PrintSequences(sequence, i, left - i);
      sequence.pop_back();
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::vector<int> sequence;
  while (--t >= 0) {
    int n;
    std::cin >> n;

    sequence.reserve(n);
    PrintSequences(sequence, 1, n);
    std::cout << "\n";
  }

  return 0;
}