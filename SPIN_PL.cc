// C++14 (gcc 8.3)
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class DisjontSets {
 public:
  DisjontSets(int n) {
    parent_.resize(n);
    rank_.resize(n);

    for (int i{0}; i < n; ++i) {
      rank_[i] = 0;
      parent_[i] = i;
    }
  }

  int FindSet(int v) {
    if (parent_[v] != v) parent_[v] = FindSet(parent_[v]);
    return parent_[v];
  }

  void UnionSets(int u, int v) {
    const int root_u{FindSet(u)};
    const int root_v{FindSet(v)};

    if (root_u != root_v) {
      if (rank_[root_u] > rank_[root_v]) {
        parent_[root_v] = root_u;
      } else {
        parent_[root_u] = root_v;
        if (rank_[root_u] == rank_[root_v]) ++rank_[root_v];
      }
    }
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

class Graph {
 public:
  Graph(int vertices, int edges = 0) : vertices_{vertices} {
    edges_.reserve(edges);
  }

  void AddEdge(int a, int b, int weight) {
    edges_.emplace_back(Edge{a, b, weight});
  }

  int MinimumSpanningTreeWeight() const {
    const auto kLessWeight = [](const Edge& lhs, const Edge& rhs) -> bool {
      return lhs.weight > rhs.weight;
    };

    int mst_weight{0};
    DisjontSets disjont_sets(vertices_);
    std::priority_queue<Edge, std::vector<Edge>, decltype(kLessWeight)> queue{
        edges_.begin(), edges_.end(), kLessWeight};

    for (int i{1}; i < vertices_; ++i) {
      Edge edge;
      do {
        edge = queue.top();
        queue.pop();
      } while (disjont_sets.FindSet(edge.a) == disjont_sets.FindSet(edge.b));

      mst_weight += edge.weight;
      disjont_sets.UnionSets(edge.a, edge.b);
    }

    return mst_weight;
  }

 private:
  struct Edge {
    int a, b;
    int weight;
  };

  const int vertices_;
  std::vector<Edge> edges_;
};

Graph ReadGraph() {
  const auto ignore_until = [](char character) -> void {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), character);
  };

  int n, m;
  ignore_until('=');
  std::cin >> n;
  ignore_until('=');
  std::cin >> m;

  Graph graph(n, m);
  while (--m >= 0) {
    int u, v, w;
    ignore_until('{');
    std::cin >> u;
    ignore_until(',');
    std::cin >> v;
    ignore_until('}');
    std::cin >> w;

    graph.AddEdge(u, v, w);
  }

  return graph;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    const Graph graph{ReadGraph()};
    std::cout << graph.MinimumSpanningTreeWeight() << "\n";
  }

  return 0;
}