#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

const int64_t MODULUS = 1000000007;

struct Input_data{
  int64_t nodes_number, moves_number;
  vector <Vertex> edges;
};

struct Edge{
  int start_node, finish_node;
};

class Matrix {
 private:
  int matrix_size;
  vector <vector<int64_t>> matrix;

  //умножение матриц
  void multiply(const Matrix &other_matrix);

  //из списка смежности в матрицу смежности
  void edges_to_matrix(const vector <Edge> &edges);

 public:
  explicit Matrix(const int matrix_size);

  explicit Matrix(const Input_data &labyrinth_parameters);

  //конструктор копирования
  Matrix(const Matrix& other_matrix);

  //сумма первого ряда
  const int64_t first_row_sum();

  //двоичное возведение в степень
  void calculate_matrix_power(int power);
};

//функция считающая пути (решающая задачу)
int64_t count_ways(const Input_data &labyrinth_parameters);

//ввод
Input_data read(std::istream& in);

//вывод ответа
void write(std::ostream& out, const int64_t number_of_ways);

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const auto &labyrinth_parameters = read(cin);
  const int64_t number_of_ways = count_ways(labyrinth_parameters);
  write(cout, number_of_ways);
  return 0;
}
