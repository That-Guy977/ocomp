#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

typedef tuple<double, int, int> path;

struct point {
  int x, y;
  point(int x, int y): x(x), y(y) {}
};

int root(int id, vector<int> map) {
  if (map[id] == id) return id;
  return map[id] = root(map[id], map);
}

int main() {
  int n;
  cin >> n;
  vector<point> universe;
  vector<int> map;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    universe.emplace_back(x, y);
    map.push_back(i);
  }
  priority_queue<path, vector<path>, greater<path>> paths;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      paths.emplace(hypot((double)(universe[i].x - universe[j].x), (double)(universe[i].y - universe[j].y)), i, j);
    }
  }
  double sum = 0;
  for (int i = 0; i < n - 1; i++) {
    double d;
    int a, b;
    do {
      tie(d, a, b) = paths.top();
      paths.pop();
    } while (root(a, map) == root(b, map));
    sum += d;
    map[b] = a;
  }
  cout << fixed << setprecision(4) << sum << endl;
  return 0;
}
