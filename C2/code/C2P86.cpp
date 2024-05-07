#include <iostream>

using namespace std;

long memo[16];

long count(int);

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < 16; i++) {
    memo[i] = -1;
  }
  memo[0] = 1;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    if (n % 2) {
      cout << 0 << endl;
    } else {
      cout << count(n / 2) << endl;
    }
  }
  return 0;
}

long count(int n) {
  if (n < 0) return 0;
  if (memo[n] != -1) return memo[n];
  long res = count(n - 1);
  for (int i = 1; i <= n; i++) {
    res += 2 * count(n - i);
  }
  memo[n] = res;
  return res;
}
