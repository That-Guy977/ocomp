#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include <cmath>
#include <climits>
#define EPSILON 0.0001

using namespace std;

typedef pair<int, int> point;

const point NONE { INT_MAX, INT_MAX };

bool travel(point, map<point, vector<point>>&, set<point>&, point, int, set<point>&, set<point>&);

int main() {
  int n;
  cin >> n;
  map<point, int> plot;
  map<point, vector<point>> graph;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    vector<point> tangents;
    for (auto [pos, r_] : plot) {
      auto [x_, y_] = pos;
      if (abs(hypot(x - x_, y - y_) - (r + r_)) < EPSILON) {
        graph[pos].push_back({ x, y });
        tangents.push_back(pos);
      }
    }
    plot[{ x, y }] = r;
    graph[{ x, y }] = tangents;
  }
  set<point> visited;
  bool check = 0;
  for (auto [pos, data] : plot) {
    if (visited.count(pos)) continue;
    set<point> a, b;
    if (travel(pos, graph, visited, NONE, 0, a, b)) {
      check = 1;
      break;
    }
  }
  cout << (check ? "YES" : "NO") << endl;
  return 0;
}

bool travel(point pos, map<point, vector<point>>& graph, set<point>& visited, point from, int color, set<point>& a, set<point>& b) {
  if (visited.count(pos)) return a.count(pos) != color;
  visited.insert(pos);
  (color ? b : a).insert(pos);
  for (point next : graph[pos]) {
    if (next == from) continue;
    else if (!travel(next, graph, visited, pos, (color + 1) % 2, a, b)) {
      return 0;
    }
  }
  if (from == NONE) {
    return a.size() != b.size();
  }
  return 1;
}
