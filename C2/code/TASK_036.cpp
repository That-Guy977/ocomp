#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

void walk(int, map<int, set<int>>&, set<int>&);

int main() {
  int n, m;
  cin >> n >> m;
  map<int, set<int>> graph;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
  }
  set<int> visited;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited.count(i)) {
      walk(i, graph, visited);
      count++;
    }
  }
  cout << count << endl;
  return 0;
}

void walk(int node, map<int, set<int>> &graph, set<int> &visited) {
  visited.insert(node);
  for (int connection : graph[node]) {
    if (!visited.count(connection)) {
      walk(connection, graph, visited);
    }
  }
}
