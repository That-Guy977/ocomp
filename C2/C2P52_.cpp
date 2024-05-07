#include <iostream>
#include <map>
#include <tuple>
#define LIMIT 1000000007

using namespace std;

map<pair<int, int>, long> memo;

long c(int, int);

int main() {
  int u, n;
  cin >> u >> n;
  if (n > 1) {
    cout << c(u - n + 1, n) << endl;
  } else {
    cout << u << endl;
  }
  return 0;
}

long c(int n, int k) {
  if (k > n / 2) k = n - k;
  if (k == 0) return 1;
  if (memo.count({ n, k })) return memo[{ n, k }];
  long res = (c(n - 1, k - 1) + c(n - 1, k)) % LIMIT;
  memo[{ n, k }] = res;
  return res;
}
