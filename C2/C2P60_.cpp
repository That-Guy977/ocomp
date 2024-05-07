#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

map<pair<int, int>, int> memo;

int subseq(string&, string&, int = 0, int = 0);

int main() {
  string a, b;
  cin >> a >> b;
  cout << subseq(a, b) << endl;
  return 0;
}

int subseq(string &a, string &b, int i, int j) {
  if (a.length() == i || b.length() == j) return 0;
  if (memo.count({ i, j })) return memo[{ i, j }];
  int res;
  if (a[i] == b[j]) {
    res = subseq(a, b, i + 1, j + 1) + 1;
  } else {
    res = max(
      subseq(a, b, i + 1, j),
      subseq(a, b, i, j + 1)
    );
  }
  memo[{ i, j }] = res;
  return res;
}
