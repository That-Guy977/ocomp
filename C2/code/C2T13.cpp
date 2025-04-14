#include <iostream>
#include <iomanip>
#include <ios>
#include <tuple>
#include <cmath>

using namespace std;

int root(pair<int, double>[], int);

int main() {
  int n, m;
  cin >> n >> m;
  pair<int, double> r[n];
  for (int i = 0; i < n; i++) {
    r[i] = { i, 1 };
  }
  cout << setprecision(4) << scientific;
  for (int mi = 0; mi < m; mi++) {
    char op;
    cin >> op;
    if (op == 'A') {
      int i, j;
      double x, y;
      cin >> i >> x >> j >> y;
      i--;
      j--;
      if (root(r, i) != root(r, j)) {
        int rj = root(r, j);
        r[rj].first = i;
        r[rj].second = x / y / r[j].second;
      } else {
        cout << "Already Known" << endl;
      }
    } else {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      c--;
      if (a == b) {
        cout << 0.0 << endl;
      } else if (root(r, a) == root(r, b) && root(r, a) == root(r, c)) {
        cout << abs(r[a].second - r[b].second) / r[c].second << endl;
      } else {
        cout << "Insufficient Data" << endl;
      }
    }
  }
  return 0;
}

int root(pair<int, double> r[], int i) {
  if (r[i].first == i) return i;
  int p = root(r, r[i].first);
  r[i].second *= r[r[i].first].second;
  r[i].first = p;
  return p;
}
