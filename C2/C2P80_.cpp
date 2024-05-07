#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

set<int> spread(map<int, vector<pair<int, int>>>&, int, int, set<int>);
int shortest(map<int, vector<pair<int, int>>>&, int, set<int>&, set<int>);

int main() {
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  map<int, vector<pair<int, int>>> graph;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].emplace_back(w, v);
    graph[v].emplace_back(w, u);
  }
  set<int> infected = spread(graph, s, e, {});
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u;
    cin >> u;
    cout << shortest(graph, u, infected, {}) << endl;
  }
  return 0;
}

set<int> spread(map<int, vector<pair<int, int>>> &graph, int s, int e, set<int> visited) {
  if (s == e) return { e };
  set<int> infected;
  visited.insert(s);
  for (const pair<int, int> &road : graph[s]) {
    int city = road.second;
    if (!visited.count(city)) {
      set<int> next = spread(graph, city, e, visited);
      if (!next.empty()) {
        infected.insert(next.begin(), next.end());
        infected.insert(s);
      }
    }
  }
  return infected;
}

int shortest(map<int, vector<pair<int, int>>> &graph, int u, set<int> &infected, set<int> visited) {
  if (infected.count(u)) return 0;
  int mn = -1;
  visited.insert(u);
  for (const pair<int, int> &road : graph[u]) {
    int time, city;
    tie(time, city) = road;
    if (!visited.count(city)) {
      int t = shortest(graph, city, infected, visited);
      if (t != -1 && (mn == -1 || t + time < mn)) mn = t + time;
    }
  }
  return mn;
}
