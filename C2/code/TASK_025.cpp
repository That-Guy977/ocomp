#include <iostream>
#include <set>
#include <map>

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
  for (int i = 1; i <= n; i++) {
    cout << i << " |";
    for (int x : graph[i]) {
      cout << " " << x;
    }
    cout << endl;
  }
  return 0;
}
