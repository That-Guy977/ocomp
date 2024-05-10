#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> roads;
  map<int, map<int, vector<int>>> city;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    roads.emplace_back(a, b);
    city[a][b];
    city[b][a];
  }
  for (int i = 0; i < m; i++) {
    int p, c;
    cin >> p >> c;
    auto [a, b] = roads[p - 1];
    city[a][b].push_back(c);
    city[b][a].push_back(c);
  }
  set<int> leaves;
  map<int, set<int>> graph;
  for (auto [s, neighbors] : city) {
    transform(
      iter(neighbors),
      inserter(graph[s], graph[s].end()),
      [](const pair<int, vector<int>>& entry) { return entry.first; }
    );
    if (neighbors.size() == 1) {
      leaves.insert(s);
    }
  }
  map<int, map<int, int>> routes;
  while (!leaves.empty()) {
    set<int> nextlayer;
    for (int leaf : leaves) {
      if (graph[leaf].empty()) break;
      int connection = *graph[leaf].begin();
      for (int i = 1; i <= n; i++) {
        if (i != leaf && !routes[leaf].count(i)) {
          routes[leaf][i] = connection;
        } else {
          routes[connection][i] = leaf;
        }
      }
      graph[connection].erase(leaf);
      if (graph[connection].size() == 1) {
        nextlayer.insert(connection);
      }
    }
    leaves = nextlayer;
  }
  // for (auto [k, m] : routes) {
  //   cout << k << ": { ";
  //   for (auto [kk, v] : m) {
  //     cout << kk << ":" << v << " ";
  //   }
  //   cout << "}" << endl;
  // }
  for (int qi = 0; qi < q; qi++) {
    int s, t, x;
    long y;
    cin >> s >> t >> x >> y;
    priority_queue<int, vector<int>, greater<int>> tolls;
    while (s != t) {
      int v = routes[s][t];
      for (int c : city[s][v]) {
        tolls.push(c);
      }
      s = v;
    }
    while (!tolls.empty() && y >= tolls.top()) {
      y -= tolls.top();
      // cout << "use silver : " << y << endl;
      tolls.pop();
    }
    // cout << "rem " << tolls.size() << endl;
    x -= tolls.size();
    cout << max(x, -1) << endl;
  }
  return 0;
}
