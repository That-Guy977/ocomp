#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

bool hasPath(map<int, set<int>>&, int, int, set<int>);

int main() {
  int v, e;
  cin >> v >> e;
  map<int, set<int>> graph;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].insert(b);
  }
  for (int i = 1; i <= v; i++) {
    cout << i;
    for (int out : graph[i]) {
      cout << "->" << out;
    }
    cout << endl;
  }
  int start, end;
  cin >> start >> end;
  cout << (hasPath(graph, start, end, {}) ? "Yes" : "No") << endl;
  return 0;
}

bool hasPath(map<int, set<int>> &graph, int start, int end, set<int> visited) {
  if (graph[start].count(end)) return true;
  for (int out : graph[start]) {
    if (!visited.count(out)) {
      set<int> next(visited);
      next.insert(out);
      if (hasPath(graph, out, end, next)) {
        return true;
      }
    }
  }
  return false;
}

