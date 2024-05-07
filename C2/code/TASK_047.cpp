#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, long> memo { { 0, 0 } };

long f(vector<long>&, int, int);

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<long> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    cout << f(a, q, c) << endl;
  }
  return 0;
}

long f(vector<long> &a, int i, int c) {
  if (memo.count(i)) return memo[i];
  set<long> r;
  for (int j = 1; j <= i; j++) {
    long nextf = f(a, j - 1, c);
    long distsq = a[i - 1] - a[j - 1];
    distsq *= distsq;
    r.insert(nextf + distsq + c);
  }
  long res = *r.begin();
  memo[i] = res;
  return res;
}
