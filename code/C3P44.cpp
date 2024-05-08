#include <iostream>
#define MOD 1000000007

using namespace std;

void matmul(int, long[], long[]);

int main() {
  long m;
  int n;
  cin >> m >> n;
  long x[n * n] = {};
  long p[n * n] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i * n + j];
      p[i * n + j] %= MOD;
      x[i * n + j] = i == j;
    }
  }
  while (m) {
    if (m & 1) {
      matmul(n, x, p);
    }
    matmul(n, p, p);
    m >>= 1;
  }
  for (int i = 0; i < n * n; i++) {
    cout << x[i];
    if ((i + 1) % n) cout << " ";
    else cout << endl;
  }
  return 0;
}

void matmul(int n, long a[], long b[]) {
  long r[n * n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[i * n + j] = 0;
      for (int k = 0; k < n; k++) {
        r[i * n + j] += a[i * n + k] * b[k * n + j] % MOD;
      }
    }
  }
  for (int i = 0; i < n * n; i++) {
    a[i] = r[i] % MOD;
  }
}
