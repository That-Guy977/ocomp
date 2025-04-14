#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

pair<short, short> farthest(map<short, set<short>>, short);
short root(short[], short);

int main() {
  short n, m, k;
  cin >> n >> m >> k;
  set<tuple<int, short, short>, greater<tuple<short, int, int>>> paths;
  for (int i = 0; i < m; i++) {
    short u, v;
    int w;
    cin >> u >> v >> w;
    u--;
    v--;
    paths.emplace(w, u, v);
  }
  short region[n];
  for (int i = 0; i < n; i++) {
    region[i] = i;
  }
  map<short, set<short>> graph;
  int count = 0;
  for (auto [w, u, v] : paths) {
    if (root(region, u) != root(region, v)) {
      count += w;
      region[root(region, u)] = root(region, v);
      if (k) {
        graph[u].insert(v);
        graph[v].insert(u);
      }
    }
  }
  int r = root(region, 0);
  for (int i = 1; i < n; i++) {
    if (root(region, i) != r) {
      goto exit;
    }
  }
  cout << count << endl;
  if (k) {
    short u = farthest(graph, 0).first;
    short dist = farthest(graph, u).second;
    cout << dist << endl;
  }
  return 0;
  exit:
  cout << "AYGOMH" << endl;
  return 0;
}

pair<short, short> farthest(map<short, set<short>> graph, short s) {
  queue<tuple<short, short, short>> search;
  search.emplace(s, 0, -1);
  short edge = 0;
  short dist = 0;
  while (!search.empty()) {
    auto [u, d, p] = search.front();
    search.pop();
    if (d > dist) {
      dist = d;
      edge = u;
    }
    for (short v : graph[u]) {
      if (v == p) continue;
      search.emplace(v, d + 1, u);
    }
  }
  return { edge, dist };
}

short root(short region[], short i) {
  if (region[i] == i) return i;
  return region[i] = root(region, region[region[i]]);
}
