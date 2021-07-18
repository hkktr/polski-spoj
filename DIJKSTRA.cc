// C++14 (gcc 8.3)
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class Graph {
 public:
  Graph(int vertices) : vertices_{vertices} {
    adjacency_list_.resize(vertices_);
  }

  void AddEdge(int a, int b, int weight) {
    adjacency_list_[a].push_back(std::make_pair(weight, b));
  }

  int ShortestPath(int source, int destination) {
    std::vector<int> distance(vertices_, std::numeric_limits<int>::max());
    std::queue<std::pair<int, int>> queue;

    distance[source] = 0;
    queue.push(std::make_pair(0, source));

    while (!queue.empty()) {
      const std::pair<int, int> current{queue.front()};
      queue.pop();

      for (const std::pair<int, int>& edge : adjacency_list_[current.second]) {
        const int new_distance{
            std::min(distance[edge.second], current.first + edge.first)};

        if (new_distance < distance[edge.second]) {
          distance[edge.second] = new_distance;
          queue.push(std::make_pair(new_distance, edge.second));
        }
      }
    }

    if (distance[destination] == std::numeric_limits<int>::max()) return -1;
    return distance[destination];
  }

 private:
  int vertices_;
  std::vector<std::vector<std::pair<int, int>>> adjacency_list_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int v, k;
    std::cin >> v >> k;

    Graph graph(v);
    while (--k >= 0) {
      int a, b, c;
      std::cin >> a >> b >> c;
      graph.AddEdge(a - 1, b - 1, c);
    }

    int a, b;
    std::cin >> a >> b;

    const int distance{graph.ShortestPath(a - 1, b - 1)};
    if (distance == -1) {
      std::cout << "NIE\n";
    } else {
      std::cout << distance << "\n";
    }
  }

  return 0;
}