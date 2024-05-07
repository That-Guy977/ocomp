#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <string>

using namespace std;

map<pair<int, int>, int> memo;

int dist(string&, int, string&, int);

int main() {
  string a, b;
  cin >> a >> b;
  cout << dist(a, 0, b, 0) << endl;
  return 0;
}

int dist(string &a, int i, string &b, int j) {
  if (a.length() == i) return b.length() - j;
  if (b.length() == j) return a.length() - i;
  if (memo.count({ i, j })) return memo[{ i, j }];
  int res;
  if (a[i] == b[j]) {
    res = dist(
      a,
      i + 1,
      b,
      j + 1
    );
  } else {
    res = min({
      dist(a, i + 1, b, j),
      dist(a, i, b, j + 1),
      dist(a, i + 1, b, j + 1),
    }) + 1;
  }
  memo[{ i, j }] = res;
  return res;
}
