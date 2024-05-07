#include <iostream>

using namespace std;

long memo[1001];

long count(int);

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 1001; i++) {
    memo[i] = -1;
  }
  memo[0] = 1;
  cout << count(n) << endl;
  return 0;
}

long count(int n) {
  if (n < 0) return 0;
  if (memo[n] != -1) return memo[n];
  long res = count(n - 1) + count(n - 2);
  for (int i = 2; i <= n; i++) {
    res += 2 * count(n - i);
  }
  for (int i = 2; i <= n; i += 2) {
    res += count(n - i);
  }
  memo[n] = res;
  return res;
}
