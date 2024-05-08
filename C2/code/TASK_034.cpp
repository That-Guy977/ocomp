#include <iostream>
#include <map>
#include <set>
#include <deque>

using namespace std;

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
  int s;
  cin >> s;
  deque<int> searchlist { s };
  set<int> visited;
  while (!searchlist.empty()) {
    int x = searchlist.back();
    searchlist.pop_back();
    if (visited.count(x)) continue;
    visited.insert(x);
    cout << x << " ";
    searchlist.insert(searchlist.end(), graph[x].rbegin(), graph[x].rend());
  }
  cout << endl;
  return 0;
}