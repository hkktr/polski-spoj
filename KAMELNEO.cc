// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

void CalculateCycleLength(const std::vector<int>& graph, int v,
                          std::vector<int>& cycle_lengths) {
  std::vector<int> cycle{v};

  int current_vertex{v};
  while ((current_vertex = graph[current_vertex - 1]) != v) {
    cycle.push_back(current_vertex);
  }

  for (int vertex : cycle) {
    cycle_lengths[vertex - 1] = static_cast<int>(cycle.size());
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> permutations;
  permutations.reserve(n);

  int input_permutation;
  while (--n >= 0) {
    std::cin >> input_permutation;
    permutations.push_back(input_permutation);
  }

  int q;
  std::cin >> q;

  std::vector<int> cycle_lengths(permutations.size(), 0);
  while (--q >= 0) {
    int a, k;
    std::cin >> a >> k;

    if (k != 0) {
      if (cycle_lengths[a - 1] == 0) {
        CalculateCycleLength(permutations, a, cycle_lengths);
      }
      k %= cycle_lengths[a - 1];
    }

    int answer{a};
    for (int i = 0; i < k; ++i) {
      answer = permutations[answer - 1];
    }
    std::cout << answer << "\n";
  }

  return 0;
}