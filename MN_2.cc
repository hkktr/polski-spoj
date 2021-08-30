// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

std::vector<double> GaussianJordanElimination(
    int n, std::vector<std::vector<double>>& matrix) {
  constexpr double kEpsilon{std::numeric_limits<double>::epsilon()};

  std::vector<int> column_indexes(n + 1);
  for (int i{0}; i <= n; ++i) column_indexes[i] = i;

  for (int i{0}; i < n - 1; ++i) {
    int new_column_index{i};
    for (int j{i + 1}; j < n; ++j) {
      if (std::fabs(matrix[i][column_indexes[new_column_index]]) <
          std::fabs(matrix[i][column_indexes[j]])) {
        new_column_index = j;
      }
    }
    std::swap(column_indexes[i], column_indexes[new_column_index]);

    for (int j{i + 1}; j < n; ++j) {
      if (std::fabs(matrix[i][column_indexes[i]]) < kEpsilon) return {};

      const double multiplier{-matrix[j][column_indexes[i]] /
                              matrix[i][column_indexes[i]]};
      for (int k{i + 1}; k <= n; ++k) {
        matrix[j][column_indexes[k]] +=
            multiplier * matrix[i][column_indexes[k]];
      }
    }
  }

  std::vector<double> solutions(n);
  for (int i{n - 1}; i >= 0; --i) {
    if (std::fabs(matrix[i][column_indexes[i]]) < kEpsilon) return {};

    double products_sum{matrix[i][n]};
    for (int j{n - 1}; j >= i + 1; --j) {
      products_sum -=
          matrix[i][column_indexes[j]] * solutions[column_indexes[j]];
    }
    solutions[column_indexes[i]] = products_sum / matrix[i][column_indexes[i]];
  }

  return solutions;
}

std::vector<std::vector<double>> GetMatrix(int m, int n) {
  std::vector<std::vector<double>> matrix(m, std::vector<double>(n));
  for (std::vector<double>& row : matrix) {
    for (double& element : row) {
      std::cin >> element;
    }
  }

  return matrix;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  std::cout << std::fixed;
  while (--t >= 0) {
    int n;
    std::cin >> n;

    std::vector<std::vector<double>> matrix{GetMatrix(n, n + 1)};
    const std::vector<double> solutions{GaussianJordanElimination(n, matrix)};

    if (solutions.empty()) {
      std::cout << "nie\n";
    } else {
      std::cout << "tak\n";
      for (double solution : solutions) {
        std::cout << solution << "\n";
      }
    }
  }

  return 0;
}