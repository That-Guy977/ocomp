#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, pair<map<int, int>, vector<int>>> graph;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].first[b] = c;
    graph[b].second.push_back(a);
  }
  map<int, unsigned> dist;
  set<int, function<bool(int, int)>> unvisited([&dist](int a, int b) {
      return dist[a] != dist[b] ? dist[a] < dist[b] : a < b;
  });
  for (int i = 1; i <= n; i++) {
    dist[i] = i == 1 ? 0 : -1;
    unvisited.insert(i);
  }
  int node = 1;
  while (node != n) {
    for (auto [neighbor, d] : graph[node].first) {
      if (!unvisited.count(neighbor)) continue;
      if (dist[node] + d < dist[neighbor]) {
        unvisited.erase(neighbor);
        dist[neighbor] = dist[node] + d;
        unvisited.insert(neighbor);
      }
    }
    unvisited.erase(node);
    node = *unvisited.begin();
  }
  int count = 0;
  for (int neighbor : graph[n].second) {
    if (dist[neighbor] + graph[neighbor].first[n] == dist[n]) count++;
  }
  cout << dist[n] << " " << count << endl;
  return 0;
}
