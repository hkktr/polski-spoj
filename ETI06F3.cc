// C++14 (gcc 8.3)
#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
 public:
  Graph(int vertices) : vertices_{vertices} {
    adjacency_list_.resize(vertices_);
  }

  void AddEdge(int a, int b) { adjacency_list_[a].push_back(b); }

  std::vector<int> ConnectedComponents() {
    std::vector<char> visited(vertices_, false);
    std::vector<int> connected_components;

    for (int v{0}; v < vertices_; ++v) {
      if (!visited[v]) {
        int count{0};
        ConnectedComponentsUtility(v, visited, count);
        if (count > 0) connected_components.push_back(count);
      }
    }

    return connected_components;
  }

 private:
  int vertices_;
  std::vector<std::vector<int>> adjacency_list_;

  void ConnectedComponentsUtility(int v, std::vector<char>& visited,
                                  int& count) {
    visited[v] = true;
    ++count;

    for (int u : adjacency_list_[v]) {
      if (!visited[u]) {
        ConnectedComponentsUtility(u, visited, count);
      }
    }
  }
};

int main() {
  int n;
  std::cin >> n;

  Graph graph(n);
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      bool acquaintance;
      std::cin >> acquaintance;
      if (acquaintance) graph.AddEdge(i, j);
    }
  }

  std::vector<int> connected_components{graph.ConnectedComponents()};
  if (connected_components.size() != 3) {
    std::cout << "NIE\n";
  } else {
    std::sort(connected_components.begin(), connected_components.end());

    std::cout << "TAK";
    for (int count : connected_components) {
      std::cout << " " << count;
    }
    std::cout << "\n";
  }

  return 0;
}