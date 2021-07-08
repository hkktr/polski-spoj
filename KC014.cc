// C++14 (gcc 8.3)
#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;

matrix_t GetSquareMatrix(std::size_t size) {
  matrix_t matrix(size, std::vector<int>(size));
  for (std::size_t i{0}; i < size; ++i) {
    for (std::size_t j{0}; j < size; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  return matrix;
}

void PrintSquareMatrix(const matrix_t& matrix) {
  const std::size_t size{matrix.size()};
  for (std::size_t i{0}; i < size; ++i) {
    for (std::size_t j{0}; j < size; ++j) {
      std::cout << matrix[i][j] << " ";
    }
  }
  std::cout << "\n";
}

matrix_t SquareMatrixProduct(const matrix_t& lhs, const matrix_t& rhs) {
  const std::size_t size{lhs.size()};
  matrix_t result(size, std::vector<int>(size));

  for (std::size_t i{0}; i < size; ++i) {
    for (std::size_t j{0}; j < size; ++j) {
      int sum{0};
      for (std::size_t k{0}; k < size; ++k) {
        sum += lhs[i][k] * rhs[k][j];
      }
      result[i][j] = sum;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::size_t size;
  while (std::cin >> size) {
    const matrix_t a{GetSquareMatrix(size)}, b{GetSquareMatrix(size)};
    PrintSquareMatrix(SquareMatrixProduct(a, b));
  }

  return 0;
}