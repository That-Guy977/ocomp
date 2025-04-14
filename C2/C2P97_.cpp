#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

int main() {
  int q;
  cin >> q;
  for (int qi = 0; qi < q; qi++) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    map<int, map<int, int>> graph;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (!graph[u][v] || graph[u][v] > w) {
        graph[u][v] = w;
        graph[v][u] = w;
      }
    }
    map<int, int> delay;
    queue<int> search;
    set<int> visited;
    delay[s] = 0;
    search.push(s);
    while (!search.empty()) {
      int u = search.front();
      search.pop();
      if (visited.count(u)) continue;
      visited.insert(u);
      for (auto [v, w] : graph[u]) {
        search.push(v);
        if (!delay[v] || delay[v] > delay[u] + w) {
          delay[v] = delay[u] + w;
        }
      }
    }
    if (delay.count(t)) {
      cout << delay[t] << endl;
    } else {
      cout << "unreachable" << endl;
    }
  }
  return 0;
}
