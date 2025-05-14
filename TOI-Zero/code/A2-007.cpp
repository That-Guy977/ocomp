#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

struct tank {
  int parent;
  int root;
  int level;
};

int main() {
  int n, m;
  cin >> n >> m;
  tank tanks[n];
  deque<pair<int, int>> edge;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    while (!edge.empty() && a > edge.back().second) edge.pop_back();
    tanks[i] = {
      edge.empty() ? -1 : edge.back().first,
      edge.empty() ? i : edge.front().first,
      (int)edge.size()
    };
    edge.emplace_back(i, b);
  }
  map<int, set<int>> detect;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    k--;
    detect[tanks[k].root].insert(k);
  }
  set<int> res;
  for (auto [k, t] : detect) {
    int mnl = -1;
    for (int i : t) {
      if (mnl == -1 || tanks[i].level < mnl) mnl = tanks[i].level;
    }
    for (int i : set(t)) {
      t.erase(i);
      while (tanks[i].level > mnl) i = tanks[i].parent;
      t.insert(i);
    }
    while (t.size() > 1) {
      for (int i : set(t)) {
        t.erase(i);
        t.insert(tanks[i].parent);
      }
    }
    res.insert(*t.begin() + 1);
  }
  cout << res.size() << endl;
  bool first = true;
  for (int t : res) {
    if (!first) cout << " ";
    first = false;
    cout << t;
  }
  cout << endl;
  return 0;
}
