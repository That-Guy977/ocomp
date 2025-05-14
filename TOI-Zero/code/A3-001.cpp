#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> section;

int maxweight(vector<section>&, int);

int main() {
  int n;
  cin >> n;
  vector<section> t;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int a, l, b, r;
    cin >> a >> l >> b >> r;
    if (a) total += l;
    if (b) total += r;
    t.emplace_back(pair{ a, a ? l : l - 1 }, pair{ b, b ? r : r - 1 });
  }
  int mx = maxweight(t, 0);
  cout << mx - total << endl;
  return 0;
}

int maxweight(vector<section>& t, int i) {
  pair<int, int> l = t[i].first;
  pair<int, int> r = t[i].second;
  return max(
    l.first ? l.second : maxweight(t, l.second),
    r.first ? r.second : maxweight(t, r.second)
  ) * 2;
}
