#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int ni = 0; ni < n; ni++) {
    map<int, vector<int>> graph;
    while (true) {
      int a, b;
      cin >> a >> b;
      if (!a && !b) break;
      graph[a].push_back(b);
    }
    double sum = 0;
    for (const pair<int,  vector<int>> &p : graph) {
      queue<int> searchlist;
      searchlist.push(p.first);
      set<int> visited;
      for (int dist = 0; !searchlist.empty(); dist++) {
        queue<int> next;
        while (!searchlist.empty()) {
          int x = searchlist.front();
          searchlist.pop();
          if (!visited.count(x)) {
            visited.insert(x);
            for (int connection : graph[x]) {
              next.push(connection);
            }
            sum += dist;
          }
        }
        while (!next.empty()) {
          int x = next.front();
          next.pop();
          searchlist.push(x);
        }
      }
    }
    printf("%.3lf\n", sum / graph.size() / (graph.size() - 1));
  }
  return 0;
}
