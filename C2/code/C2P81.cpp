#include <iostream>
#include <map>
#include <tuple>

using namespace std;

map<pair<int, int>, long> memo;

long c(int, int);

int main() {
  int n, k;
  cin >> n >> k;
  cout << c(n, k) << endl;
  return 0;
}

long c(int n, int k) {
  if (k == 0 || k == n) return 1;
  if (k > n / 2) k = n - k;
  if (memo.count({ n, k })) return memo[{ n, k }];
  long res = c(n - 1, k - 1) + c(n - 1, k);
  memo[{ n, k }] = res;
  return res;
}
