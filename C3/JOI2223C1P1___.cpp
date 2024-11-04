#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> roads;
  map<int, map<int, int>> routes;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    roads.emplace_back(a, b);
    map<int, int> ar = routes[a];
    map<int, int> br = routes[b];
    for (auto [an, _] : ar) {
      routes[b][an] = a;
      routes[an][b] = routes[an][a];
      for (auto [bn, _] : br) {
        routes[an][bn] = routes[an][a];
        routes[bn][an] = routes[bn][b];
      }
    }
    for (auto [bn, _] : br) {
      routes[a][bn] = b;
      routes[bn][a] = routes[bn][b];
    }
    routes[a][b] = b;
    routes[b][a] = a;
  }
  map<int, map<int, vector<int>>> tollmap;
  for (int i = 0; i < m; i++) {
    int p, c;
    cin >> p >> c;
    auto [a, b] = roads[p - 1];
    tollmap[a][b].push_back(c);
    tollmap[b][a].push_back(c);
  }
  for (int qi = 0; qi < q; qi++) {
    int s, t, x;
    long y;
    cin >> s >> t >> x >> y;
    map<int, int> tolls;
    while (s != t) {
      int v = routes[s][t];
      for (int c : tollmap[s][v]) {
        tolls[c]++;
      }
      s = v;
    }
    while (!tolls.empty()) {
      auto [fee, times] = *tolls.begin();
      int p = min((int)(y / fee), times);
      y -= fee * p;
      if (p == times) {
        tolls.erase(tolls.begin());
      } else {
        tolls[fee] -= p;
        break;
      }
    }
    for (auto [fee, times] : tolls) {
      x -= times;
      if (x < 0) {
        x = -1;
        break;
      }
    }
    cout << x << endl;
  }
  return 0;
}
