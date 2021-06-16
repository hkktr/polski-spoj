// C++14 (gcc 8.3)
#include <iostream>
#include <queue>
#include <vector>

class Graph {
 public:
  Graph(int vertices) : vertices_{vertices} {
    adjacency_list_.resize(vertices_);
    visited_.resize(vertices_);
  }

  void AddEdge(int a, int b) { adjacency_list_[a].push_back(b); }

  void PrintBFS(int v) {
    ClearVisited();
    visited_[v] = true;

    std::queue<int> queue;
    queue.push(v);

    while (!queue.empty()) {
      const int u{queue.front()};
      queue.pop();
      std::cout << u + 1 << " ";

      for (int n : adjacency_list_[u]) {
        if (!visited_[n]) {
          visited_[n] = true;
          queue.push(n);
        }
      }
    }

    std::cout << "\n";
  }

  void PrintDFS(int v) {
    ClearVisited();
    PrintDFSUtility(v);
    std::cout << "\n";
  }

 private:
  int vertices_;
  std::vector<std::vector<int>> adjacency_list_;
  std::vector<char> visited_;

  void PrintDFSUtility(int v) {
    visited_[v] = true;
    std::cout << v + 1 << " ";

    for (int n : adjacency_list_[v]) {
      if (!visited_[n]) {
        PrintDFSUtility(n);
      }
    }
  }

  void ClearVisited() {
    for (char& state : visited_) {
      state = false;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  for (int graph_id{0}; graph_id < t; ++graph_id) {
    int n;
    std::cin >> n;
    Graph graph(n);

    while (--n >= 0) {
      int i, m;
      std::cin >> i >> m;

      while (--m >= 0) {
        int b;
        std::cin >> b;
        graph.AddEdge(i - 1, b - 1);
      }
    }

    std::cout << "graph " << graph_id + 1 << "\n";
    while (true) {
      int v, i;
      std::cin >> v >> i;
      if (v == 0 && i == 0) break;

      if (i == 0) {
        graph.PrintDFS(v - 1);
      } else {
        graph.PrintBFS(v - 1);
      }
    }
  }

  return 0;
}