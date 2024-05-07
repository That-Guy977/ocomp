#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

int main() {
  int nc;
  cin >> nc;
  map<int, vector<int>> graph;
  for (int i = 0; i < nc; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  while (true) {
    int origin, ttl;
    cin >> origin >> ttl;
    if (!origin && !ttl) break;
    vector<int> searchlist { origin };
    set<int> visited;
    for (int i = 0; i <= ttl; i++) {
      set<int> next;
      for (int node : searchlist) {
        if (visited.count(node)) continue;
        visited.insert(node);
        next.insert(graph[node].begin(), graph[node].end());
      }
      searchlist.clear();
      searchlist.insert(searchlist.end(), next.begin(), next.end());
    }
    cout << graph.size() - visited.size() << endl;
  }
  return 0;
}
