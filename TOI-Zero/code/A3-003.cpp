#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    a.push_back(p);
  }
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    b.push_back(p);
  }
  int ap = 1;
  int bp = 1;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (set{ ap, a[i], bp, b[i] }.size() % 2 == 0) {
      vector<pair<int, int>> pl {
        { ap, 0 },
        { a[i], 0 },
        { bp, 1 },
        { b[i], 1 },
      };
      sort(iter(pl));
      if (pl[0].second == pl[2].second) count++;
    }
    ap = a[i];
    bp = b[i];
  }
  cout << count << endl;
  return 0;
}
