#include <iostream>
#include <algorithm>

using namespace std;

unsigned long cost(int, int, int, int, int[], long[]);

int main() {
  int m, n;
  cin >> m >> n;
  int city[m * n];
  long memo[m * n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> city[i * n + j];
      memo[i * n + j] = -1;
    }
  }
  cout << cost(0, 0, m, n, city, memo) << endl;
  return 0;
}

unsigned long cost(int i, int j, int m, int n, int city[], long memo[]) {
  if (i >= m || j >= n) return -1;
  if (memo[i * n + j] != -1) return memo[i * n + j];
  if (i == m - 1 && j == n - 1) return city[i * n + j];
  unsigned long res = min({
    cost(i + 1, j, m, n, city, memo),
    cost(i, j + 1, m, n, city, memo),
    cost(i + 1, j + 1, m, n, city, memo)
  }) + city[i * n + j];
  memo[i * n + j] = res;
  return res;
}
