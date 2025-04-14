#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <tuple>
#define iter(c) c.begin(), c.end()

using namespace std;

map<int, int> memo;

int maximize(vector<pair<int, int>>&, int = 0);

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
      int s, e;
      cin >> s >> e;
      events.emplace_back(s, e);
    }
    sort(iter(events));
    for (int i = 0; i < n; i++) {
      events[i].second = distance(events.begin(), lower_bound(
        events.begin() + i,
        events.end(),
        pair{ events[i].second, 0 }
      ));
    }
    for (auto [x, y] : events) cout << x << ":" << y << endl; cout << endl;
    cout << maximize(events) << endl;
    memo.clear();
  }
  return 0;
}

int maximize(vector<pair<int, int>>& events, int i) {
  if (memo.count(i)) return memo[i];
  if (i == events.size()) return 0;
  int res = max(
    maximize(events, i + 1),
    maximize(events, events[i].second) + 1
  );
  memo[i] = res;
  return res;
}
