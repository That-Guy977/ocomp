#include <iostream>
#include <map>
#include <tuple>

using namespace std;

map<pair<int, int>, long> memo;

long place(int, int);

int main() {
  int u, n;
  cin >> u >> n;
  if (n > 1) {
    long count = 0;
    for (int i = 0; i < u - n; i++) {
      count += place(u - i, n - 1);
    }
    cout << count << endl;
  } else {
    cout << u << endl;
  }
  return 0;
}

long place(int u, int n) {
  if (n == 0) return 1;
  if (memo.count({ u, n })) return memo[{ u, n }];
  long res = 0;
  for (int i = 2; i <= u - n; i++) {
    res += place(u - i, n - 1);
  }
  memo[{ u, n }] = res;
  return res;
}
