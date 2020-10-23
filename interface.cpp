#include <iostream>
#include <vector>

const int64_t MOD = 1000000007;

class Matrix {
 public:
  int nodes;
  std::vector <std::vector<int64_t>> matrix;

  explicit Matrix(int node_number);
  Matrix(const Matrix& other_matrix);

  void vertices_input(int vertex_number);

  const int64_t first_row_sum();

  void multiply(const Matrix& other_matrix);

  void binary_power(int pow);
};

Matrix read_matrix(int64_t* moves);

int64_t count_ways(Matrix Labyrinth, int64_t moves);

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int64_t moves;
  Matrix Labyrinth = read_matrix(&moves);

  std::cout << count_ways(Labyrinth, moves);
  return 0;
}
