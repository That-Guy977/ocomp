#include <iostream>

using namespace std;

long memo[91];

long count(int, int);

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    memo[i] = -1;
  }
  memo[0] = 1;
  cout << count(n, m) << endl;
  return 0;
}

long count(int n, int m) {
  if (n < 0) return 0;
  if (memo[n] != -1) return memo[n];
  long res = count(n - 1, m) + count(n - m, m);
  memo[n] = res;
  return res;
}
