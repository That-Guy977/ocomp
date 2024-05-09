#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#define MOD 1000000007

using namespace std;

typedef array<long, 25> matrix;

long t(long, int, int, int, int, int);
matrix matmul(matrix, matrix);

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int q;
  cin >> q;
  for (int qi = 0; qi < q; qi++) {
    long k;
    cin >> k;
    cout << t(k, a, b, c, d, e) << endl;
  }
  return 0;
}

long t(long k, int a, int b, int c, int d, int e) {
  static matrix p {
    a, b, 0, 0, c,
    1, 0, 0, 0, 0,
    0, 1, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 1, 0,
  };
  static vector<matrix> powers { p };
  if (k == 0 || k == 1) return 1;
  if (k == 2 || k == 3) return d;
  if (k == 4) return e;
  matrix factor {
    1, 0, 0, 0, 0,
    0, 1, 0, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 0, 1, 0,
    0, 0, 0, 0, 1,
  };
  k -= 4;
  for (int i = 0; k; i++) {
    if (powers.size() <= i) {
      powers.push_back(matmul(powers.back(), powers.back()));
    }
    if (k & 1) {
      factor = matmul(factor, powers[i]);
    }
    k >>= 1;
  }
  return (
    + e * factor[0] % MOD
    + d * factor[1] % MOD
    + d * factor[2] % MOD
    + 1 * factor[3] % MOD
    + 1 * factor[4] % MOD
  ) % MOD;
}

matrix matmul(matrix a, matrix b) {
  matrix r = {};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        r[i * 5 + j] += a[i * 5 + k] * b[k * 5 + j] % MOD;
      }
    }
  }
  transform(r.begin(), r.end(), r.begin(), [](long x) { return x % MOD; });
  return r;
}
