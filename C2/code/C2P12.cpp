#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main() {
  int m, n, op;
  cin >> m >> n >> op;
  set<int> a, b;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.insert(x);
  }
  set<int> r;
  switch (op) {
    case 0:
      set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.begin()));
      break;
    case 1:
      set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.begin()));
      break;
    case 2:
      set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.begin()));
      break;
  }
  for (int x : r) {
    cout << x << " ";
  }
  cout << endl;
}
