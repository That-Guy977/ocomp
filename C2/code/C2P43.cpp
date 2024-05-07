#include <iostream>

using namespace std;

long memo[51];

long fib(int);

int main() {
  for (int i = 0; i < 51; i++) {
    memo[i] = -1;
  }
  int x;
  cin >> x >> memo[0] >> memo[1];
  cout << fib(x) << endl;
  return 0;
}

long fib(int x) {
  if (memo[x] != -1) return memo[x];
  long res = fib(x - 1) + fib(x - 2);
  memo[x] = res;
  return res;
}
