#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

const int64_t MODULUS = 1000000007;

struct Input_data{
  int64_t node_number, moves_number;
  vector <pair <int, int> > vertices;
};

class Matrix {
 private:
  int nodes;
  vector <vector<int64_t>> matrix;

  //умножение матриц
  void multiply(const Matrix& other_matrix);

  //из списка смежности в матрицу смежности
  void vertices_to_matrix(const vector <pair <int, int> > &vertices);

 public:
  explicit Matrix(int node_number);

  explicit Matrix(const Input_data &data);

  //конструктор копирования
  Matrix(const Matrix& other_matrix);

  //сумма первого ряда
  const int64_t first_row_sum();

  //двоичное возведение в степень
  void binary_power(int pow);
};

//функция считающая пути (решающая задачу)
int64_t count_ways(const Input_data &data);

//ввод
Input_data read(std::istream& in);

//вывод ответа
void write(std::ostream& out, int64_t number_of_ways);

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const auto &data = read(cin);
  int64_t number_of_ways = count_ways(data);
  write(cout, number_of_ways);
  return 0;
}
