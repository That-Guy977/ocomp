#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, m, t, d;
  cin >> n >> m >> t >> d;
  set<int> roots;
  for (int i = 0; i < n; i++) {
    roots.insert(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    roots.erase(v);
  }
  vector<int> plan;
  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    plan.emplace_back(y);
  }
  int time = 0;
  for (int i = 0; i < t && roots.size() > d + 1; i++) {
    roots.erase(plan[i]);
    time++;
  }
  if (roots.size() <= d + 1) {
    cout << time << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
