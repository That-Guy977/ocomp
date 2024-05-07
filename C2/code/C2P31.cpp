#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

struct edge {
  int to;
  int weight;
  bool operator<(const edge &other) const {
    return to < other.to;
  }
};

int main() {
  int v, e;
  cin >> v >> e;
  map<int, set<edge>> graph;
  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    graph[a].insert({ b, w });
    graph[b].insert({ a, w });
  }
  vector<int> path;
  while (true) {
    int x;
    cin >> x;
    if (x == -1) break;
    path.push_back(x);
  }
  set<int> visited { path.front() };
  int pos = 0;
  int weight = 0;
  int cycle = 0;
  for (int node : path) {
    if (!pos) {
      pos = node;
      continue;
    }
    set<edge>::iterator it = graph[pos].find({ node });
    if (it != graph[pos].end()) {
      pos = node;
      weight += it->weight;
      if (visited.count(node)) {
        cycle = 1;
        break;
      } else {
        visited.insert(node);
      }
    } else {
      break;
    }
  }
  set<int> uniqpath(visited.begin(), visited.end());
  cout << visited.size() - 1 + cycle << " " << weight << endl;
  return 0;
}
