#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int v, e;
  cin >> v >> e;
  map<int, set<int>> graph;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
  }
  vector<int> path;
  while (true) {
    int x;
    cin >> x;
    if (x == -1) break;
    path.push_back(x);
  }
  vector<int> visited { path.front() };
  int pos = 0;
  for (int node : path) {
    if (!pos) {
      pos = node;
      continue;
    }
    if (graph[pos].count(node)) {
      pos = node;
      visited.push_back(node);
    } else {
      break;
    }
  }
  set<int> uniqpath(visited.begin(), visited.end());
  cout << path.front()
    << " " << visited.back()
    << " " << visited.size() - 1
    << " " << (visited.size() == uniqpath.size() ? "NO" : "YES")
  << endl;
  return 0;
}
