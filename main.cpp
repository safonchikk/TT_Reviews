#include <iostream>
#include <vector>

const int64_t MOD = 1E9 + 7;

class matrix{
 public:
  int n;
  std::vector <std::vector<int64_t>> m;
  explicit matrix(int i){
    n = i;
    std::vector <std::vector<int64_t>> k(n, std::vector <int64_t> (n, 0));
    m = k;
  }
};

matrix mult(matrix a, matrix b){
  int n = a.n;
  matrix res = matrix(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k){
        res.m[i][j] += a.m[i][k]*b.m[k][j];
        res.m[i][j] = res.m[i][j] % MOD;
      }
  return res;
}

matrix sqr(matrix a){
  int n = a.n;
  matrix res = matrix(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k){
        res.m[i][j] += a.m[i][k]*a.m[k][j];
        res.m[i][j] = res.m[i][j] % MOD;
      }
  return res;
}

matrix bin_pow(matrix a, int64_t n){
  if (n == 1)
    return a;
  if (n % 2)
    return mult(bin_pow(a, n - 1), a);
  return sqr(bin_pow(a, n/2));
}

int main(){
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  matrix A = matrix(n);
  int a, b;
  for (int i = 0; i < m; ++i){
    std::cin >> a >> b;
    ++A.m[a-1][b-1];
  }
  if (k == 0){
    std::cout << 1;
    return 0;
  }
  matrix B = bin_pow(A, k);
  int64_t res = 0;
  for (int i = 0; i < n; ++i)
    res += B.m[0][i];
  res = res % MOD;
  std::cout << res;
  return 0;
}
