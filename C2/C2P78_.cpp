#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct edge {
  int t;
  int x;
  int y;
};

int main() {
  int c;
  cin >> c;
  for (int ci = 0; ci < c; ci++) {
    int n, m;
    cin >> n >> m;
    vector<edge> graph;
    for (int i = 0; i < m; i++) {
      int x, y, t;
      cin >> x >> y >> t;
      graph.push_back({ t, x, y });
    }
    vector<int> distance(n, -1);
    distance[0] = 0;
    for (int i = 0; i < n; i++) {
      for (edge &e : graph) {
        int time = distance[e.x] + e.t;
        if (distance[e.y] == -1 || time < distance[e.y]) {
          distance[e.y] = time;
        }
      }
    }
    bool negcycle = false;
    for (edge &e : graph) {
      if (distance[e.x] + e.t < distance[e.y]) {
        negcycle = true;
        break;
      }
    }
    cout << (negcycle ? "possible" : "not possible") << endl;
  }
  return 0;
}
