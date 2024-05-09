#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  int c[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  map<int, vector<pair<int, int>>> graph;
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    graph[a].emplace_back(b, t);
    graph[b].emplace_back(a, t);
  }
  map<int, pair<vector<int>, int>> paths;
  
  return 0;
}
