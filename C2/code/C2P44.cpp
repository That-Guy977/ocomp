#include <iostream>

using namespace std;

long memo[51] = { 0, 1, 1, 2, 4 };

long c(int);

int main() {
  int n;
  cin >> n;
  cout << c(n) << endl;
  return 0;
}

long c(int x) {
  if (memo[x]) return memo[x];
  long res = c(x - 1) + c(x - 3) + c(x - 4);
  memo[x] = res;
  return res;
}
