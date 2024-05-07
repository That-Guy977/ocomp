#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int v, e;
  cin >> v >> e;
  map<int, pair<set<int>, int>> graph;
  for (int i = 0; i < e; i++) {
    int from, to;
    cin >> from >> to;
    graph[from].first.insert(to);
    graph[to].second++;
  }
  for (int i = 1; i <= v; i++) {
    cout << graph[i].second << " " << graph[i].first.size() << endl;
  }
  return 0;
}
