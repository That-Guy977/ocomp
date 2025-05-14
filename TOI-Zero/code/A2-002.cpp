#include <iostream>
#include <map>
#include <tuple>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, pair<int, int>> diaga;
  map<int, pair<int, int>> diagb;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int a = x + y;
    int b = x - y;
    if (!diaga.count(a)) {
      diaga[a] = { b, b };
    } else {
      if (b < diaga[a].first) diaga[a].first = b;
      if (b > diaga[a].second) diaga[a].second = b;
    }
    if (!diagb.count(b)) {
      diagb[b] = { a, a };
    } else {
      if (a < diagb[b].first) diagb[b].first = a;
      if (a > diagb[b].second) diagb[b].second = a;
    }
  }
  int mx = 0;
  for (auto [d, v] : diaga) {
    auto [a, b] = v;
    if (b - a > mx) mx = b - a;
  }
  for (auto [d, v] : diagb) {
    auto [a, b] = v;
    if (b - a > mx) mx = b - a;
  }
  cout << mx / 2 << endl;
  return 0;
}
